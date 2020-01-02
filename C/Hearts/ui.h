#ifndef __UI_H__
#define __UI_H__
#include "DV.h"

/* 
Description: prints diffrent types data or instructions
Input: varries
Output: to stdio
Error: none
*/

void CardsPrint( Vector* _givenArray1, Vector* _givenArray2, Vector* _givenArray3, Vector* _givenArray4);
void GameOverPrint();
void SwapCardsPrint();
void CardsInTrickPrint(const int* _givenArray, int _givenSize);
int GetCardScan();
void DoNotHaveCardPrint();
void RoundScorePrint(const char* _givenArray, char _size, char _roundNum);

/*extra features TODO*/
void WelcomePrint();
void TrickResult();
void PlayerNameScan();


#endif /*__UI_H__*/
