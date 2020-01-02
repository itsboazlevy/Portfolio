#include <stdlib.h>
#include "deck.h"
#define SHUFFLE_SWAP_AMOUNT 1000

char* DeckCreate(int _numOfCards)
{
	char* myDeck;
	int count;
	myDeck = (char*)malloc(sizeof(char)*_numOfCards);
	if (myDeck == NULL)
	{
		return NULL;
	}
	for(count = 0; count < _numOfCards; count++)
	{
		myDeck[count] = count;
	}
	return myDeck;
}

gameErr DeckShuffle(char* _myDeck, int _numOfCards)
{
	int count, randCard, randCard2;
	char tempCard;
	if (_myDeck == NULL)
	{
		return NULL_ERR;
	}
	for (count = 0; count < SHUFFLE_SWAP_AMOUNT; count++)
	{
		randCard = rand()%_numOfCards;
		randCard2 = rand()%_numOfCards;
		tempCard = _myDeck[randCard];
		_myDeck[randCard] = _myDeck[randCard2];
		_myDeck[randCard2] = tempCard;
	}
	return SUCCESS;
}

gameErr DeckGetCard(const char* _myDeck, int _cardIndex, char* _gotCard)
{
	if (_myDeck == NULL)
	{
		return NULL_ERR;
	}
	*_gotCard = _myDeck[_cardIndex];
	return SUCCESS;
}

void DeckDestroy(char* _myDeck)
{
	if (_myDeck == NULL)
	{
		return;
	}
	free(_myDeck);
	return;
}
