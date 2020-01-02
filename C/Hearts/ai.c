#include "ai.h"
#include <stdlib.h>

int AIPickCard(Vector* _myHearts, Vector* _mySpades, Vector* _myDiamonds, Vector* _myClubs, int* _cardsInTrick, int _numOfCardsInTrick)
{
	int heartsAmount;
	int spadesAmount;
	int diamondsAmount;
	int clubsAmount;
	int totalAmount;
	int pickedCardIndex;
	int pickedCard;
	VectorGetItemsNum(_myHearts, &heartsAmount);
	VectorGetItemsNum(_mySpades, &spadesAmount);
	VectorGetItemsNum(_myDiamonds, &diamondsAmount);
	VectorGetItemsNum(_myClubs, &clubsAmount);
	totalAmount = heartsAmount+spadesAmount+diamondsAmount+clubsAmount;
	pickedCardIndex = rand()%totalAmount;
	
	if (pickedCardIndex < heartsAmount)
	{ 	
		VectorGet(_myHearts,pickedCardIndex, &pickedCard);
	}
	else if (pickedCardIndex < heartsAmount+spadesAmount)
	{ 	
		VectorGet(_mySpades,pickedCardIndex-heartsAmount, &pickedCard);
	}
	else if (pickedCardIndex < heartsAmount+spadesAmount+diamondsAmount)
	{ 	
		VectorGet(_myDiamonds,pickedCardIndex-heartsAmount-spadesAmount, &pickedCard);
	}
	else
	{ 	
		VectorGet(_myClubs,pickedCardIndex-heartsAmount-spadesAmount-diamondsAmount, &pickedCard);
	}
	return pickedCard;
}

