#include <iostream>

using namespace std;

// ===========  VARIABLES ===========

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


// ===========  INITIALISATION ===========
void setup()
{
    gameOver = false;
    //snake is not moving

    eDirection = STOP;
    // center the snake on the map
    x = width/2;
    y = height/2;

    // randomize fruit position
    fruitX = rand()%width;
    fruitY = rand()%height;
}


void Draw()
{

}

void Input()
{

}

void logic()
{

}

int main()
{
    setup();

    while (!gameOver)
    {
        Draw();
        Input();
        logic();

    }

    return 0;
}
