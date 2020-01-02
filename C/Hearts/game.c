#include <stdlib.h>
#include "game.h"
#define CREATION_NUM 12345678
#define AI 0
#define HUMAN 1
#define NUM_OF_PLAYERS 4
#define MAX_SCORE 100

struct Game
{
	char m_numOfPlayers;
	char m_numOfAI;
	char* m_scoreBoard;
	Player** m_playerPtrs;
	char m_roundNum;
	int m_creationNum;
};

static gameErr CreatePlayers(Game* _myGame,int _numOfPlayers, int _numOfAI)
{
	int count;
	Player* tempPlayerPtr;
	for(count = 0; count < _numOfPlayers; count++)
	{
		if (_numOfPlayers-_numOfAI > 0)
		{
			tempPlayerPtr = PlayerCreate(HUMAN);
			_numOfAI++;
		}
		else
		{
		tempPlayerPtr = PlayerCreate(AI);
		}
		if (tempPlayerPtr == NULL)
		{
			while(count>0)
			{
				PlayerDestroy(_myGame->m_playerPtrs[count-1]);
				count--;
			}
			return NULL_ERR;
		}
		_myGame->m_playerPtrs[count] = tempPlayerPtr;
	}
	return SUCCESS;	
}

Game* GameCreate(int _numOfPlayers, int _numOfAI)
{
	Game* myGame;
	if(_numOfPlayers != NUM_OF_PLAYERS || _numOfAI > _numOfPlayers || _numOfAI < 0 )
	{
		return NULL;
	}
	myGame = (Game*)calloc(1,sizeof(Game));
	if (myGame == NULL)
	{
		return NULL;
	}
	myGame->m_playerPtrs = (Player**)calloc(_numOfPlayers,sizeof(Player*));
	if (myGame->m_playerPtrs == NULL)
	{
		free(myGame);
		return NULL;
	}
	myGame->m_scoreBoard = (char*)calloc(_numOfPlayers,sizeof(char));
	if (myGame->m_scoreBoard == NULL)
	{
		free(myGame->m_playerPtrs);
		free(myGame);
		return NULL;
	}
	if (CreatePlayers(myGame, _numOfPlayers, _numOfAI) == NULL_ERR)
	{
		free(myGame->m_scoreBoard);
		free(myGame->m_playerPtrs);
		free(myGame);
		return NULL;
	}
	myGame->m_creationNum = CREATION_NUM;
	myGame->m_numOfPlayers = _numOfPlayers;
	myGame->m_numOfAI = _numOfAI;
	return myGame; 
}

gameErr GamePlay(Game* _myGame)
{
	int count;
	char tempScoreBoard[NUM_OF_PLAYERS] = {0};
	Round* myRound;
	if (_myGame == NULL || _myGame->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	while(1)
	{
		for(count = 0; count < _myGame->m_numOfPlayers; count++)
		{
			if (_myGame->m_scoreBoard[count] > MAX_SCORE)
			{
				GameOverPrint();
				GameDestroy(_myGame);
				return GAME_OVER;	
			}
		}
		_myGame->m_roundNum += 1;
		myRound = RoundCreate(_myGame->m_roundNum, _myGame->m_numOfPlayers, _myGame->m_playerPtrs);
		if (myRound == NULL)
		{
			return ROUND_ALLOC_ERR;
		}
		RoundPlay(myRound,tempScoreBoard);
		for(count = 0; count < _myGame->m_numOfPlayers; count++)
		{
			_myGame->m_scoreBoard[count] += tempScoreBoard[count];
			tempScoreBoard[count] = 0;
		}
		RoundScorePrint(_myGame->m_scoreBoard,_myGame->m_numOfPlayers, _myGame->m_roundNum);
		RoundDestroy(myRound);
	}
}

void GameDestroy(Game* _myGame)
{
	int count;
	if (_myGame == NULL || _myGame->m_creationNum != CREATION_NUM)
	{
		return;
	}
	for(count = 0; count < _myGame->m_numOfPlayers ; count++)
	{
		PlayerDestroy(_myGame->m_playerPtrs[count]);
	}
	_myGame->m_creationNum = 0;
	free(_myGame->m_scoreBoard);
	free(_myGame->m_playerPtrs);
	free(_myGame);
	return;
}

