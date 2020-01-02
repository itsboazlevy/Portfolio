#include <stdlib.h>
#include <string.h>
#include "player.h"
#define AI 0
#define HUMAN 1
#define CREATION_NUM 23456781
#define VECTOR_INITIAL_SIZE 2
#define VECTOR_EXTENSION_BLOCK 2
#define CARD_SYMBOL(n) n/13
#define CARD_NUM(n) n%13
#define HEARTS 0
#define SPADES 1
#define DIAMONDS 2
#define CLUBS 3
#define COUNTING_SORT_RANGE 52
#define CLUBS2 39

struct Player
{
	Vector* m_hearts;
	Vector* m_spades;
	Vector* m_diamonds;
	Vector* m_clubs;
	char m_playerType;
	char* m_playerName;
	char m_playerScore;
	int m_creationNum;
};

static ADTErr CountingSort(Vector* _vec, int _range);
static gameErr CardsAllocations(Player* _myPlayer);
static gameErr DoesPlayerHaveCard (const Player* _myPlayer, int _card);

static ADTErr CountingSort(Vector* _vec, int _range)
{
	int *tempArr,*tempArr2;
	int vecSize,count,tempItem;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	tempArr = (int*)calloc(_range,sizeof(int));
	if (tempArr == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}
	tempArr2 = (int*)calloc(vecSize,sizeof(int));
	if (tempArr2 == NULL)
	{
		free(tempArr);
		return ERR_ALLOCATION_FAILED;
	}
	for(count = 0; count < vecSize ;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr[tempItem]++;
	}
	for(count = 1; count < _range;count++)
	{
		tempArr[count] += tempArr[count-1];
	}
	for(count = _range-1; count > 0;count--)
	{
		tempArr[count] = tempArr[count-1];
	}
	tempArr[0] = 0;
	for(count = 0; count < vecSize;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr2[tempArr[tempItem]] = tempItem;
		tempArr[tempItem]++;
	}
	for(count = 0; count < vecSize;count++)
	{
		VectorSet(_vec, count, tempArr2[count]);
	}
	free(tempArr);
	free(tempArr2);
	return ERR_OK;
}

static gameErr CardsAllocations(Player* _myPlayer)
{
	int flag = 0;
	_myPlayer->m_spades = VectorCreate(VECTOR_INITIAL_SIZE, VECTOR_EXTENSION_BLOCK);
	if (_myPlayer->m_spades == NULL)
	{
		flag++;
	}
	_myPlayer->m_hearts = VectorCreate(VECTOR_INITIAL_SIZE, VECTOR_EXTENSION_BLOCK);
	if (_myPlayer->m_hearts == NULL)
	{
		flag++;
	}
	_myPlayer->m_clubs = VectorCreate(VECTOR_INITIAL_SIZE, VECTOR_EXTENSION_BLOCK);
	if (_myPlayer->m_clubs == NULL)
	{
		flag++;
	}
	_myPlayer->m_diamonds = VectorCreate(VECTOR_INITIAL_SIZE, VECTOR_EXTENSION_BLOCK);
	if (_myPlayer->m_diamonds == NULL)
	{
		flag++;
	}
	if (flag != 0)
	{
		VectorDestroy (_myPlayer->m_hearts);
		VectorDestroy (_myPlayer->m_spades);
		VectorDestroy (_myPlayer->m_diamonds);
		VectorDestroy (_myPlayer->m_clubs);
		return NULL_ERR;
	}
	return SUCCESS;
}

static gameErr DoesPlayerHaveCard (const Player* _myPlayer, int _card)
{
	int tempItemsNum, tempItem;
	int count;
	Vector* tempVectorPtr;
	switch (CARD_SYMBOL(_card))
	{
		case HEARTS:	tempVectorPtr = _myPlayer->m_hearts;
						break;
		case SPADES:	tempVectorPtr = _myPlayer->m_spades;
						break;
		case DIAMONDS:	tempVectorPtr = _myPlayer->m_diamonds;
						break;
		case CLUBS:		tempVectorPtr = _myPlayer->m_clubs;
						break;
	}
	VectorGetItemsNum(tempVectorPtr, &tempItemsNum);
	for(count = 0; count < tempItemsNum; count++)
	{
		VectorGet(tempVectorPtr, count, &tempItem);
		if (_card == tempItem)
		{
			return SUCCESS;
		}
	}
	return FAIL;
}


Player* PlayerCreate(char _playerType)
{
	Player* myPlayer;
	myPlayer = (Player*)calloc(1,sizeof(Player));
	if (myPlayer == NULL)
	{
		return NULL;
	}
	myPlayer->m_playerName = (char*)malloc(sizeof(char)*20);
	if (myPlayer->m_playerName == NULL)
	{
		free(myPlayer);
		return NULL;
	}
	if (CardsAllocations(myPlayer) == NULL_ERR)
	{
		free(myPlayer->m_playerName);
		free(myPlayer);
		return NULL;
	}
	myPlayer->m_playerType = _playerType;
	myPlayer->m_playerScore = 0;
	strcpy(myPlayer->m_playerName,"AI");
	myPlayer->m_creationNum = CREATION_NUM;
	return myPlayer;
}

void PlayerDestroy(Player* _myPlayer)
{
	if (_myPlayer == NULL || _myPlayer->m_creationNum != CREATION_NUM)
	{
		return;
	}
	_myPlayer->m_creationNum = 0;

	VectorDestroy (_myPlayer->m_hearts);
	VectorDestroy (_myPlayer->m_spades);
	VectorDestroy (_myPlayer->m_diamonds);
	VectorDestroy (_myPlayer->m_clubs);
	free(_myPlayer->m_playerName);
	free(_myPlayer);
	return;
}	

gameErr PlayerDoesNotHaveSymbol(const Player* _myPlayer,int _cardSymbol)
{
	int tempItemsNum;
	switch (_cardSymbol)
	{
		case HEARTS:	VectorGetItemsNum(_myPlayer->m_hearts, &tempItemsNum);
						break;
		case SPADES:	VectorGetItemsNum(_myPlayer->m_spades, &tempItemsNum);
						break;
		case DIAMONDS:	VectorGetItemsNum(_myPlayer->m_diamonds, &tempItemsNum);
						break;
		case CLUBS:		VectorGetItemsNum(_myPlayer->m_clubs, &tempItemsNum);
						break;
	}
	if ( tempItemsNum == 0)
	{
		return SUCCESS;
	}
	return FAIL;
}

gameErr PlayerGotOnlyHearts(const Player* _myPlayer)
{
	int tempItemsNum;
	VectorGetItemsNum(_myPlayer->m_spades, &tempItemsNum);
	if ( tempItemsNum != 0)
	{
		return FAIL;
	}
	VectorGetItemsNum(_myPlayer->m_diamonds, &tempItemsNum);
	if ( tempItemsNum != 0)
	{
		return FAIL;
	}
	VectorGetItemsNum(_myPlayer->m_clubs, &tempItemsNum);
	if ( tempItemsNum != 0)
	{
		return FAIL;
	}
	return SUCCESS;
}

gameErr PlayerCardsPrint(const Player* _myPlayer)
{
	CardsPrint(_myPlayer->m_hearts,_myPlayer->m_spades,_myPlayer->m_diamonds,_myPlayer->m_clubs);
	return SUCCESS;
}

gameErr PlayerSortCards(Player* _myPlayer)
{
	CountingSort(_myPlayer->m_hearts,COUNTING_SORT_RANGE);
	CountingSort(_myPlayer->m_spades,COUNTING_SORT_RANGE);
	CountingSort(_myPlayer->m_diamonds,COUNTING_SORT_RANGE);
	CountingSort(_myPlayer->m_clubs,COUNTING_SORT_RANGE);
	return SUCCESS;
}

gameErr PlayerAddCard(Player* _myPlayer,char _givenCard)
{
	switch(CARD_SYMBOL(_givenCard))
	{
		case HEARTS:	VectorAdd(_myPlayer->m_hearts, _givenCard);
				break;
		case SPADES:	VectorAdd(_myPlayer->m_spades, _givenCard);
				break;
		case DIAMONDS:	VectorAdd (_myPlayer->m_diamonds, _givenCard);
				break;
		case CLUBS:	VectorAdd (_myPlayer->m_clubs, _givenCard);
				break;
	}
	return SUCCESS;
}

gameErr PlayerIsFirst(const Player* _myPlayer)
{
	int item;
	VectorGet(_myPlayer->m_clubs, 0,&item);
	if (item == CLUBS2)
	{
		return SUCCESS;
	}
	return FAIL;
}


gameErr PlayerIsHuman(const Player* _myPlayer)
{
	if (_myPlayer->m_playerType == HUMAN)
	{
		return SUCCESS;
	}
	return FAIL;
}


gameErr PlayerPickCard( Player* _myPlayer, int* _cardsInTrick, int _numOfCardsInTrick, int* _card)
{
	int tempCard;
	if ( _myPlayer->m_playerType == HUMAN)
	{
		CardsPrint(_myPlayer->m_hearts,_myPlayer->m_spades,_myPlayer->m_diamonds,_myPlayer->m_clubs);
		CardsInTrickPrint(_cardsInTrick, _numOfCardsInTrick);
		while(1)
		{
			tempCard = GetCardScan();
			if (DoesPlayerHaveCard (_myPlayer,tempCard) == SUCCESS)
			{
				break;
			}
			DoNotHaveCardPrint();
		}
	}
	else
	{
		tempCard = AIPickCard(_myPlayer->m_hearts,_myPlayer->m_spades,_myPlayer->m_diamonds,_myPlayer->m_clubs, _cardsInTrick, _numOfCardsInTrick);
	}
	*_card = tempCard;
	return SUCCESS;
}

gameErr PlayerRemoveCard(Player* _myPlayer, int _givenCard)
{
	int tempItemsNum, tempItem;
	int count;
	Vector* tempVector;
	switch (CARD_SYMBOL(_givenCard))
	{
		case HEARTS:	tempVector = _myPlayer->m_hearts;
						break;
		case SPADES:	tempVector = _myPlayer->m_spades;
						break;		
		case DIAMONDS:	tempVector = _myPlayer->m_diamonds;
						break;
		case CLUBS:		tempVector = _myPlayer->m_clubs;
						break;
	}
	VectorGetItemsNum(tempVector, &tempItemsNum);
	for(count = 0; count < tempItemsNum; count++)
	{
		VectorGet(tempVector, count, &tempItem);
		if (_givenCard == tempItem)
		{
			VectorGet(tempVector,tempItemsNum-1, &tempItem);
			VectorSet(tempVector,count, tempItem);
			VectorDelete (tempVector, &tempItem);
			CountingSort(tempVector,COUNTING_SORT_RANGE);
		}
	}
	return SUCCESS;
}

