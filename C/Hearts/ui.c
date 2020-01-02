#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ui.h"
#define CARD_NUM(n) n%13
#define CARD_SYMBOL(n) n/13
#define AI 0
#define HUMAN 1

#define NORMAL          "\x1B[0m"
#define BLACK           "\x1b[30m"
#define RED             "\x1B[31m"
#define YELLOW          "\x1B[33m"
#define MAGENTA         "\x1B[35m"
#define CYAN            "\x1B[36m"
#define HEART           "\xE2\x99\xA5 "
#define SPADE           "\xE2\x99\xA0 "
#define DIAMOND         "\xE2\x99\xA6 "
#define CLUB            "\xE2\x99\xA3 "

static void CardsUIValuePrint(int _card)
{
	switch (_card)
	{
		case 9:		printf("%c ",'J');
					break;
		case 10:	printf("%c ",'Q');
					break;
		case 11:	printf("%c ",'K');
					break;		
		case 12:	printf("%c ",'A');
					break;		
		default: 	printf("%d ",_card+2);
					break;
	}	
}

void RoundScorePrint(const char* _givenArray, char _size, char _roundNum)
{
	int count;
	printf("Round %d Final Score:\n",_roundNum);
	for(count = 0; count < _size; count++)
		{
			printf("Player 1: %d  ", _givenArray[count]);
		}
	printf("\n");
	return;
}

void DoNotHaveCardPrint()
{
	printf("--You don't have the chosen card, pick again!--\n");
	return;
}
void GameOverPrint()
{
	printf("--GAME OVER--\n");
	return;
}

void SwapCardsPrint()
{
	printf("--Pick a card to hand over--\n");
	return;
}

void CardsPrint( Vector* _givenArray1, Vector* _givenArray2, Vector* _givenArray3, Vector* _givenArray4)
{
	size_t count;
	int tempCard, tempSize;
	printf("Your Cards:\n");
	printf("%s%s%s ",RED,HEART,NORMAL);
	VectorGetItemsNum(_givenArray1, &tempSize);
	for(count = 0; count< tempSize; count++)
	{
		VectorGet(_givenArray1, count, &tempCard);
		CardsUIValuePrint(CARD_NUM(tempCard));
	}
	printf("%s%s%s",YELLOW,SPADE,NORMAL);
	VectorGetItemsNum(_givenArray2, &tempSize);
	for(count = 0; count< tempSize; count++)
	{
		VectorGet(_givenArray2, count, &tempCard);
		CardsUIValuePrint(CARD_NUM(tempCard));
	}
	printf("%s%s%s ",RED,DIAMOND,NORMAL);
	VectorGetItemsNum(_givenArray3, &tempSize);
	for(count = 0; count< tempSize; count++)
	{
		VectorGet(_givenArray3, count, &tempCard);
		CardsUIValuePrint(CARD_NUM(tempCard));
	}
	printf("%s%s%s",YELLOW,CLUB,NORMAL);
	VectorGetItemsNum(_givenArray4, &tempSize);
	for(count = 0; count< tempSize; count++)
	{
		VectorGet(_givenArray4, count, &tempCard);
		CardsUIValuePrint(CARD_NUM(tempCard));
	}
	printf("\n");
	return;
}

void CardsInTrickPrint(const int* _givenArray, int _givenSize)
{
	int count;
	printf("Cards on table:\n");
	for (count = 0; count < _givenSize; count++)
	{
		if( _givenArray[count] == -1)
		{
			break;
		}
		else
		{
			switch(CARD_SYMBOL(_givenArray[count]))
			{
				case 0: printf("%s%s%s ",RED,HEART,NORMAL);
						CardsUIValuePrint(CARD_NUM(_givenArray[count]));
						break;
				case 1: printf("%s%s%s",YELLOW,SPADE,NORMAL);
						CardsUIValuePrint(CARD_NUM(_givenArray[count]));
						break;
				case 2: printf("%s%s%s ",RED,DIAMOND,NORMAL);
						CardsUIValuePrint(CARD_NUM(_givenArray[count]));
						break;
				case 3: printf("%s%s%s",YELLOW,CLUB,NORMAL);
						CardsUIValuePrint(CARD_NUM(_givenArray[count]));
						break;
			}
		}
	}
	printf("\n");
	return;
}

int GetCardScan()
{
	int card,flag;
	int chosenSymbol;
	int chosenNum;
	while(1)
	{
		card = 0;
		flag = 0;
		printf("Enter suite 1-Hearts 2-Spades 3-Diamonds 4-Clubs\n");
		scanf("%d",&chosenSymbol);
		printf("Enter card 2-10/11/12/13/1\n");
		scanf("%d",&chosenNum);
		printf("\n");
		switch(chosenSymbol)
		{
			case 1: break;
			case 2: card+=13;
					break;
			case 3: card+=26;
					break;
			case 4: card+=39;
					break;
			default:flag = 1;
		}
		
		switch(chosenNum)
		{
			case 2:		card += 0;
						break;
			case 3:		card += 1;
						break;
			case 4:		card += 2;
						break;
			case 5:		card += 3;
						break;
			case 6:		card += 4;
						break;
			case 7:		card += 5;
						break;
			case 8:		card += 6;
						break;
			case 9:		card += 7;
						break;
			case 10:	card += 8;
						break;
			case 11:	card += 9;
						break;
			case 12:	card += 10;
						break;
			case 13:	card += 11;
						break;
			case 1:		card += 12;
						break;
			default:	flag = 1;
		}
		if (flag == 0)
		{
			break;
		}
	}
	return card;
}

