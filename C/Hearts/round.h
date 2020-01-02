#ifndef __ROUND_H__
#define __ROUND_H__
#include "deck.h"
#include "player.h"
#include "ui.h"
#include "gameErr.h"

typedef struct Round Round;

/* 
Description: creates a new Round struct
Input:  round number, number of players, pointer to player pointers array
Output: pointer to Round struct
Error: NULL if failed
*/
Round* RoundCreate(char _roundNum, char _numOfPlayers, Player** _playerPtrs); 

/* 
Description: deals shuffled cards to players , swaps 3 chosen cards, manages tricks - validates moves are valid and determines results, updates scores
Input:  pointer to round struc and pointer to array of scores
Output: SUCCESS
Error:  DECK_ALLOC_ERR if there was problem with deck allocation
*/
gameErr RoundPlay(Round* _myRound, char* _gameScoreBoard);

/* 
Description: destroys round 
Input: pointer to Round struct 
Output: none
Error: none
*/
void RoundDestroy(Round* _myRound); 

#endif /*__ROUND_H__*/
