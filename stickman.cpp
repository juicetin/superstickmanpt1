#include "stickman.h"

void Stickman::render(QPainter &painter, unsigned int time, QPixmap stickman_anim[], Settings * settings)
{
    std::string ssize = settings->getElement("size"); //CONFIG VARIABLE

    int start_pos = strtol(settings->getElement("start_x").c_str(),0,10);    //CONFIG VARIABLE

    int xcoord = start_pos;
    int ycoord;
    int dimens;

    //Place depending on size to be running above ground
    if (strcmp(ssize.c_str(), "tiny") == 0)
    {
        ycoord = 485;
        dimens = 30;
    }

    if (strcmp(ssize.c_str(), "normal") == 0)
    {
        ycoord = 465;
        dimens = 50;
    }

    if (strcmp(ssize.c_str(), "large") == 0)
    {
        ycoord = 445;
        dimens = 70;
    }

    if (strcmp(ssize.c_str(), "giant") == 0)
    {
        ycoord = 395;
        dimens = 120;
    }

    int velocity = strtol(settings->getElement("start_v").c_str(),0,10);    //CONFIG VARIABLE Uglier solution than std::stoi. Qtcreator is missing it...
    int chsprite_every_n_frames = 7-velocity/2;
    int frames_per_anim = 6;

    painter.drawPixmap(QRect(xcoord, ycoord, dimens, dimens), stickman_anim[time / chsprite_every_n_frames % frames_per_anim]);
}

Stickman::~Stickman()
{

}

