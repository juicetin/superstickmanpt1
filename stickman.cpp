#include "stickman.h"

void Stickman::render(QPainter &painter, unsigned int time, QPixmap stickman_anim[])
{
    //PLACEHOLDER
    int size = NORMAL;  //CONFIG VARIABLE

    // int test = time % 12;
    // if (test >= 0 && test < 3)
    //     size = SMALL;
    // else if (test >= 3 && test < 6)
    //     size = NORMAL;
    // else if (test >= 6 && test < 9)
    //     size = LARGE;
    // else if (test >= 9 && test < 12)
    //     size = GIANT;

    int start_pos = 40;     //CONFIG VARIABLE

    int xcoord = start_pos;
    int ycoord;
    int dimens;

    //Place depending on size to be running above ground
    if (size == SMALL)
    {
        ycoord = 485;
        dimens = 30;
    }
    else if (size == NORMAL)
    {
        ycoord = 465;
        dimens = 50;
    }
    else if (size == LARGE)
    {
        ycoord = 445;
        dimens = 70;
    }
    else if (size == GIANT)
    {
        ycoord = 395;
        dimens = 120;
    }
    
    painter.drawPixmap(QRect(xcoord, ycoord, dimens, dimens), stickman_anim[time / 3 % 7]);
}

Stickman::~Stickman()
{

}

