#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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

    dir = STOP ;
    // center the snake on the map
    x = width/2;
    y = height/2;

    // randomize fruit position
    fruitX = rand()%width;
    fruitY = rand()%height;

    score = 0;
}


void Draw()
{
    //clear screen
    system("cls");


    // ======== DRAW MAP ========

    //display top border of map
    for (int i =0; i< width+2; i++)
        cout << "#" ;
    cout<<endl;

    for (int i = 0; i<height; i++)
    {

        for (int j=0; j<width; j++)
        {
            if (j == 0)
                cout <<"#";

                cout << " ";
            if (j == width-1)
                cout << "#";
        }
        cout<<endl;
    }

    //display bottom border
    for (int i =0; i< width+2; i++)
        cout << "#" ;
    cout<<endl;



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
