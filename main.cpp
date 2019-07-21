#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

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

            //display the head
            if (x==j && y==i)

                cout << "o";

            // display the fruit

            else if (fruitX == j && fruitY == i)
                cout << "*";

            else
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

    //display score
    cout<< "Score : " << score<<endl;



}

void Input()
{
    if (_kbhit())
    {

        //leyboard control input
        switch (_getch())
        {
        case 'q':
            dir = LEFT;
            break;
        case 'z':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        default :
            break;
        }
    }
}

void logic()
{

    // movement management
    switch  (dir)
    {
    case DOWN :

        if (y<height-1)
            y++;
        break;

    case UP:
        if (y>0)
            y--;
        break;

    case LEFT:
        if (x>0)
            x--;
        break;

    case RIGHT:
        if (x<width-1)
            x++;
        break;
    default :
        break;
    }

    // if the snake hits the wall
    //if (x == width || y =z= height || x == 0 || y == 0)
    //    gameOver = true;

    //if the snake eats a fruit


    // score display and new fruit apparition
    if (x==fruitX && y==fruitY)
    {
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;

    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        Draw();
        Input();
        logic();

        Sleep(100);

    }

    return 0;
}
