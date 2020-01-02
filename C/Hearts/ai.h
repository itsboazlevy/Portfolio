#ifndef __AI_H__
#define __AI_H__
#include "gameErr.h"
#include "DV.h"

/* 
Description: helps AI pick an optimal card for winning - currently AI picks random card from its cards
Input:  cards of the AI, cards in trick, number of cards in trick
Output: picked card
Error: none
*/
int AIPickCard(Vector* _myHearts, Vector* _mySpades, Vector* _myDiamonds, Vector* _myClubs, int* _cardsInTrick, int _numOfCardsInTrick);


#endif /*__AI_H__*/
