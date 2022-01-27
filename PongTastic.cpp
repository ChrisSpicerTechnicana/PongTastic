
#include <time.h>
#include <windows.h>

#include "Ball.h"
#include "Direction.h"
#include "Paddle.h"
#include "GameEngine.h"

using namespace std;

int main()
{
	GameEngine engine(40, 20);
	engine.run();
	return 0;
}
