#include "stickman.h"

void Stickman::render(QPainter &painter, unsigned int time, QPixmap stickman_anim[])
{
    //PLACEHOLDER
    int size = GIANT;  //CONFIG VARIABLE

    int cycle = 100;
    int test = time % cycle;
    if (test >= 0 && test < cycle/4)
       size = SMALL;
   else if (test >= cycle/4 && test < cycle/2)
       size = NORMAL;
   else if (test >= cycle/2 && test < 3*cycle/4)
       size = LARGE;
   else if (test >= 3*cycle/4 && test < cycle)
       size = GIANT;

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

    int velocity = 2; //CONFIG VARIABLE;
    int chsprite_every_n_frames = 10-velocity/2;
    int frames_per_anim = 6;

    painter.drawPixmap(QRect(xcoord, ycoord, dimens, dimens), stickman_anim[time / chsprite_every_n_frames % frames_per_anim]);
}

Stickman::~Stickman()
{

}

