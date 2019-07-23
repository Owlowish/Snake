#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<time.h>

using namespace std;

// ===========  VARIABLES ===========

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
//arrays

int tailx[100],taily[100];
int ntail;


// ===========  INITIALISATION ===========
void setup()
{
    gameOver = false;
    //snake is not moving
    srand(time(0));

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
                cout << "F";

            else
            {
                bool print = false;
                for (int k = 0; k < ntail ; k++)
                {

                    if (tailx[k]== j && taily[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }

                }
                    if(!print)
                    cout << " ";

            }
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
    //remember previous coordinate
    int prevx = tailx[0];
    int prevy = taily[0];

    int prev2x,prev2y;

    tailx[0] = x;
    taily[0] = y;

    for (int i=1; i<ntail; i++)
    {

        //remember current position
        prev2x = tailx[i];
        prev2y = taily[i];

        // change value

        tailx[i] = prevx;
        taily[i] = prevy;

        prevx = tailx[i];
        prevy = taily[i];

    }



    // movement management
    switch  (dir)
    {
    case DOWN :

        if (y<height)
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
        if (x<width)
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
        ntail++;

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
