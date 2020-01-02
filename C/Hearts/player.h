#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "ai.h"
#include "ui.h"
#include "gameErr.h"
#include "DV.h"

typedef struct Player Player;

/* 
Description: create a new player
Input: player type
Output: pointer to Player struct
Error: NULL if failed
*/
Player* PlayerCreate(char _playerType);

/* 
Description: destroys player
Input: pointer to Player struct
Output: none
Error: none
*/
void PlayerDestroy(Player* _myPlayer);

/* 
Description: removes card from player by card value
Input: pointer to Player struct, card to remove
Output: SUCCSES
Error: none
*/
gameErr PlayerRemoveCard(Player* _myPlayer, int _givenCard);

/* 
Description: gives player a card
Input: pointer to Player struct
Output: SUCSSES
Error: NULL_ERR for null pointer, OVERFLOW_ERR if player reached maximum amount of cards
*/
gameErr PlayerAddCard(Player* _myPlayer,char _givenCard);

/* 
Description: prints all cards of a player
Input: pointer to Player struct
Output: SUCCESS 
Error: none
*/
gameErr PlayerCardsPrint(const Player* _myPlayer);

/* 
Description: sorts all cards of a player
Input: pointer to Player struct
Output: SUCCESS
Error: none
*/
gameErr PlayerSortCards(Player* _myPlayer);

/* 
Description: checks if player should start a round or not
Input: pointer to Player struct
Output: SUCCESS if has 2 of spades.
Error: none
*/
gameErr PlayerIsFirst(const Player* _myPlayer);

/* 
Description: checks if player has only hearts cards
Input: pointer to Player struct
Output: SUCCESS if true FAIL if not
Error: none
*/
gameErr PlayerGotOnlyHearts(const Player* _myPlayer);

/* 
Description: checks if player does not have a specific suit/symbol
Input: pointer to Player struct, card symbol/suit
Output: SUCCESS if true FAIL if not
Error: none
*/
gameErr PlayerDoesNotHaveSymbol(const Player* _myPlayer,int _cardSymbol);

/* 
Description: checks type of player
Input: pointer to Player struct
Output: SUCCESS if true FAIL if not
Error: none
*/
gameErr PlayerIsHuman(const Player* _myPlayer);

/* 
Description: gets a card from player
Input: pointer to Player struct, cards in trick array, num of cards in trick, pointer to picked card
Output: SUCCESS
Error: none
*/
gameErr PlayerPickCard( Player* _myPlayer, int* _cardsInTrick, int _numOfCardsInTrick, int* _card);

#endif /*__PLAYER_H__*/
