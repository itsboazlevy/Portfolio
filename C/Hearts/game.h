#ifndef __GAME_H__
#define __GAME_H__
#include "player.h"
#include "round.h"
#include "ui.h"
#include "gameErr.h"

typedef struct Game Game;

/*
Description: create a new game - only 4 is accepted for number of players
Input: number of players and how many AIs 
Output: pointer to Game struct
Error: NULL if failed
*/
Game* GameCreate(int _numOfPlayers, int _howManyAI);

/*
Description: runs the game and operates it, updates scoreboard and loops rounds until game is over.
Input: pointer to Game struct
Output: GAME_OVER if no errors occurd
Error: ROUND_ALLOC_ERR if allocation failed
*/
gameErr GamePlay(Game* _myGame);

/*
Description: destroys game 
Input: pointer to Game struct 
Output: none
Error: none
*/
void GameDestroy(Game* _myGame);

#endif /*__GAME_H__*/
