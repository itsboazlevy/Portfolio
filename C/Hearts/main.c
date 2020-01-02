#include "game.h"

int main()
{
	Game* myGame = GameCreate(4,4);
	GamePlay(myGame);
	GameDestroy(myGame);
	return 1;
}
