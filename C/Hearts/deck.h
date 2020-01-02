#ifndef __DECK_H__
#define __DECK_H__
#include "gameErr.h"
/* 
Description: creates a new deck with number of cards
Input: number of cards in deck
Output: pointer to deck
Error: NULL if failed
*/
char* DeckCreate(int _numOfCards);

/* 
Description: shuffles a given deck with given number of cards
Input: deck pointer and number of cards
Output: SUCCESS 
Error: NULL_ERR for null pointer
*/
gameErr DeckShuffle(char* _myDeck, int _numOfCards);

/* 
Description: moves card from deck by index and inserts to given card pointer
Input: deck pointer, index of card, card pointer
Output: SUCCESS
Error: NULL_ERR for null pointer
*/
gameErr DeckGetCard(const char* _myDeck, int _cardIndex, char* _gotCard);

/* 
Description: destroys cards deck
Input: deck pointer
Output: none
Error: none
*/
void DeckDestroy(char* _myDeck);

#endif /*__DECK_H__*/
