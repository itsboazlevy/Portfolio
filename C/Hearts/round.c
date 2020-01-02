#include <stdlib.h>
#include "round.h"
#define CREATION_NUM 34567812
#define CARDS_IN_DECK 52
#define CARDS_SWAP_AMOUNT 3
#define NUM_OF_CARDS_PER_PLAYER 13
#define CARD_SYMBOL(n) n/13
#define CARD_NUM(n) n%13
#define HEARTS 0
#define SPADES 1
#define DIAMONDS 2
#define CLUBS 3
#define SPADES_QUEEN 23
#define NUM_OF_TRICKS 13
#define AI 0
#define HUMAN 1
#define CLUBS2 39
struct Round
{
	Player** m_playerPtrs;
	int m_numOfPlayers;
	char m_roundNum;
	int m_startingPlayer;
	char m_isHeartBroken;
	char m_trickNum;
	int* m_cardsInTrick;
	int m_numOfCardsInTrick;
	int m_creationNum;
};

static gameErr RoundSwapAllCards(Round* _myRound);
static gameErr RoundDealCards(Player** _m_playerPtrs, char* _myDeck);
static char CheckWhoStarts(Round* _myRound);
static int StartRoundWithClubs2Limitation(Round* _myRound);
static int HeartsNotBrokenLimitation(Round* _myRound);
static int PlayByLeadLimitation(Round* _myRound, int _count);
static gameErr Trick(Round* _myRound, char* _tempScoreBoard);

static gameErr RoundSwapAllCards(Round* _myRound)
{
	int count,count2,count3,pattern;
	int cardsSwapArray[12];
	/*does not swap if round is fully divided by 4*/
	if (_myRound->m_roundNum%4 == 0)
	{
		return SUCCESS;
	}
	/*creates array of all removed cards*/
	for(count = 0 ,count3 = 0; count < _myRound->m_numOfPlayers; count++)
	{
		for (count2 = 0; count2 < CARDS_SWAP_AMOUNT; count2++)
		{
			if (PlayerIsHuman(_myRound->m_playerPtrs[count]))
			{
				SwapCardsPrint();
			}
			PlayerPickCard(_myRound->m_playerPtrs[count], _myRound->m_cardsInTrick, _myRound->m_numOfCardsInTrick, cardsSwapArray+count3);
			PlayerRemoveCard(_myRound->m_playerPtrs[count], cardsSwapArray[count3]);
			count3++;
		}
	}
	/*determines addition pattern*/
	switch (_myRound->m_roundNum%4)
	{
		case 1: pattern = 1;
				break;
		case 2: pattern = 3;
				break;
		case 3: pattern = 2;
				break;
	}
	/*preforms addition*/
	for(count = 0, count3 = 0; count < _myRound->m_numOfPlayers; count++)
	{
		for (count2 = 0; count2 < CARDS_SWAP_AMOUNT; count2++)
		{
			PlayerAddCard(_myRound->m_playerPtrs[(count+pattern)%_myRound->m_numOfPlayers], cardsSwapArray[count3]);
			count3++;
		}
	}
	/*sorts cards*/
	for (count = 0; count < _myRound->m_numOfPlayers; count++)
	{
			PlayerSortCards(_myRound->m_playerPtrs[count]);
	}
	return SUCCESS;
}

static gameErr RoundDealCards(Player** _m_playerPtrs, char* _myDeck)
{
	int status,count,count2;
	char givenCard;
	for(count = 0, count2 = 0; count < CARDS_IN_DECK; count++)
	{
		status = DeckGetCard(_myDeck,count,&givenCard);
		if (status == NULL_ERR)
		{
			return NULL_ERR;
		}
		PlayerAddCard(_m_playerPtrs[count2], givenCard);
		if (count%13 == 12)
		{
			PlayerSortCards(_m_playerPtrs[count2]);
			count2++;
		}
	}
	return SUCCESS;
}

static char CheckWhoStarts(Round* _myRound)
{
	int count;
	for (count = 0; count < _myRound->m_numOfPlayers; count++)
	{
		if (PlayerIsFirst(_myRound->m_playerPtrs[count]) == SUCCESS)
		{
			return count;
		}
	}
	return count;
}	


static int StartRoundWithClubs2Limitation(Round* _myRound)
{
	int chosenCard;
	while(1)
	{
		PlayerPickCard(_myRound->m_playerPtrs[_myRound->m_startingPlayer], _myRound->m_cardsInTrick, _myRound->m_numOfCardsInTrick, &chosenCard);
		if (chosenCard == CLUBS2)
		{
				break;
		}
	}
	return chosenCard;
}

static int HeartsNotBrokenLimitation(Round* _myRound)
{
	int chosenCard;
	while(1)
	{
		PlayerPickCard(_myRound->m_playerPtrs[_myRound->m_startingPlayer], _myRound->m_cardsInTrick, _myRound->m_numOfCardsInTrick, &chosenCard);
		if (CARD_SYMBOL(chosenCard) == HEARTS)
		{	
			if (PlayerGotOnlyHearts(_myRound->m_playerPtrs[(_myRound->m_startingPlayer)]) == SUCCESS)
			{
				 _myRound->m_isHeartBroken = 1;
				break;
			}
			continue;
		}
		break;
	}
	return chosenCard;
}

static int PlayByLeadLimitation(Round* _myRound, int _count)
{
	int chosenCard;
	while(1)
	{
		PlayerPickCard(_myRound->m_playerPtrs[(_myRound->m_startingPlayer+_count)%4], _myRound->m_cardsInTrick, _myRound->m_numOfCardsInTrick, &chosenCard);
		if ( CARD_SYMBOL(chosenCard) != CARD_SYMBOL(_myRound->m_cardsInTrick[0]))
		{
			if (PlayerDoesNotHaveSymbol(_myRound->m_playerPtrs[(_myRound->m_startingPlayer+_count)%4],CARD_SYMBOL(_myRound->m_cardsInTrick[0])) == SUCCESS)
			{
				/*checks - in first round, if chosen heart or queen of spades - and player has diamonds or spades, do not allow */
				if (_myRound->m_trickNum == 1)
				{
					if (	(CARD_SYMBOL(chosenCard) == HEARTS || chosenCard == SPADES_QUEEN) && 
							(	PlayerDoesNotHaveSymbol(_myRound->m_playerPtrs[(_myRound->m_startingPlayer+_count)%4],DIAMONDS) == FAIL || 
							PlayerDoesNotHaveSymbol(_myRound->m_playerPtrs[(_myRound->m_startingPlayer+_count)%4],SPADES) == FAIL    )    )
					{
						continue;
					}			
				}	
				if ( CARD_SYMBOL(chosenCard) == HEARTS)
				{
					_myRound->m_isHeartBroken = 1;	
				}
				break;	
			}
			continue;
		}
		break;
	}
	return chosenCard;
}

static gameErr Trick(Round* _myRound, char* _tempScoreBoard)
{
	int count;
	int trickScore = 0;
	int loserIndex = _myRound->m_startingPlayer;
	int loserCard;
	int chosenCard;
	_myRound->m_numOfCardsInTrick = 0;
	/*initialise cards in play*/
	for (count = 0; count < _myRound->m_numOfPlayers; count++)
	{
		_myRound->m_cardsInTrick[count] = -1;
	}
	/*verify players start round with 2 of clubs*/
	if( _myRound->m_trickNum == 1)
	{
		chosenCard = StartRoundWithClubs2Limitation(_myRound);
	}
	/*verify player do not start round with hearts until hearts are broken or hes out of other cards*/
	else if (_myRound->m_isHeartBroken == 0)
	{
		chosenCard = HeartsNotBrokenLimitation(_myRound);
	}
	else
	{
		PlayerPickCard(_myRound->m_playerPtrs[_myRound->m_startingPlayer], _myRound->m_cardsInTrick, _myRound->m_numOfCardsInTrick, &chosenCard);
	}
	PlayerRemoveCard(_myRound->m_playerPtrs[_myRound->m_startingPlayer], chosenCard);
	_myRound->m_cardsInTrick[0] = chosenCard;
	loserCard = chosenCard;
	_myRound->m_numOfCardsInTrick++;
	/*trick execution*/
	for (count = 1; count < _myRound->m_numOfPlayers; count++)
	{
		/*verify player plays by lead if he can*/
		chosenCard = PlayByLeadLimitation(_myRound, count);
		PlayerRemoveCard(_myRound->m_playerPtrs[(_myRound->m_startingPlayer+count)%4] ,chosenCard);
		_myRound->m_cardsInTrick[count] = chosenCard;
		_myRound->m_numOfCardsInTrick++;
	}
	/*amounts the score of the trick*/
	for (count = 0; count < _myRound->m_numOfPlayers; count++)
	{
		if (CARD_SYMBOL(_myRound->m_cardsInTrick[count]) == HEARTS)
		{
			trickScore += 1;
		}
		if (_myRound->m_cardsInTrick[count] == SPADES_QUEEN)
		{
			trickScore += 12;
		}
	}
	/*checks who lost*/
	for (count = 1; count < _myRound->m_numOfPlayers; count++)
	{
		if ((CARD_SYMBOL(_myRound->m_cardsInTrick[0]) == CARD_SYMBOL(_myRound->m_cardsInTrick[count])) && loserCard < _myRound->m_cardsInTrick[count])
		{
			loserIndex = (count+_myRound->m_startingPlayer)%_myRound->m_numOfPlayers;
			loserCard = _myRound->m_cardsInTrick[count];
		}
	}
	/*updates the score*/
	_tempScoreBoard[loserIndex] += trickScore;
	/*updates the starting player*/
	_myRound->m_startingPlayer = loserIndex;
	return SUCCESS;
}

gameErr RoundPlay(Round* _myRound, char* _tempScoreBoard)
{
	char* myDeck;
	int count;
	myDeck = DeckCreate(CARDS_IN_DECK);
	if (myDeck == NULL)
	{
		return DECK_ALLOC_ERR;
	}
	DeckShuffle(myDeck,CARDS_IN_DECK);
	RoundDealCards(_myRound->m_playerPtrs,myDeck);
	DeckDestroy(myDeck);
	RoundSwapAllCards(_myRound);
	_myRound->m_startingPlayer = CheckWhoStarts(_myRound);
	for ( count = 0; count < NUM_OF_TRICKS; count++)
	{
		_myRound->m_trickNum += 1;
		Trick(_myRound,_tempScoreBoard);
	}
	return 1;
}

Round* RoundCreate(char _roundNum, char _numOfPlayers, Player** _playerPtrs)
{
	Round* myRound;
	myRound = (Round*)calloc(1,sizeof(Round));
	if (myRound == NULL)
	{
		return NULL;
	}
	myRound->m_cardsInTrick = (int*)calloc(_numOfPlayers,sizeof(int));
	if (myRound->m_cardsInTrick == NULL)
	{
		free(myRound);
		return NULL;
	}
	myRound->m_playerPtrs = _playerPtrs;
	myRound->m_numOfPlayers = _numOfPlayers;
	myRound->m_roundNum = _roundNum;
	myRound->m_creationNum = CREATION_NUM;
	return myRound;
}

void RoundDestroy(Round* _myRound)
{
	if (_myRound == NULL || _myRound->m_creationNum != CREATION_NUM)
	{
		return;
	}
	_myRound->m_creationNum = 0;
	free(_myRound->m_cardsInTrick);
	free(_myRound);
	return;
}

