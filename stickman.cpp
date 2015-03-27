#include "stickman.h"

void Stickman::render(QPainter &painter, unsigned int time, QPixmap stickman_anim[], Settings * settings)
{
    int height = strtol(settings->getElement("window_height").c_str(),0,10);
    int width = strtol(settings->getElement("window_width").c_str(),0,10);

    std::string size = settings->getElement(size_tag); //CONFIG VARIABLE

    int start_pos = strtol(settings->getElement("start_x").c_str(),0,10);    //CONFIG VARIABLE

    int xcoord = start_pos;
    int ycoord;
    int dimens;

//    int base_y = 485;
    int base_y = 0.80833333*height;
    int base_dimens = height/20;

    int extra_size = 0;

    //Place depending on size to be running above ground
    if (strcmp(size.c_str(), size_small) == 0)
    {
        ycoord = base_y - extra_size;
        dimens = base_dimens + extra_size;
    }

    else if (strcmp(size.c_str(), size_normal) == 0)
    {
        extra_size = height/30;
        ycoord = base_dimens - extra_size;
        dimens = base_dimens + extra_size;
    }

    else if (strcmp(size.c_str(), size_large) == 0)
    {
        extra_size = height/15;
        ycoord = base_dimens - extra_size;
        dimens = base_dimens + extra_size;
    }

    else if (strcmp(size.c_str(), size_giant) == 0)
    {
        extra_size = height/5;
        ycoord = base_y - extra_size;
        dimens = base_dimens + extra_size;
    }

    int velocity = strtol(settings->getElement("start_v").c_str(),0,10);    //CONFIG VARIABLE Uglier solution than std::stoi. Qtcreator is missing it...
    int chsprite_every_n_frames = 7-velocity/2;
    int frames_per_anim = 6;

    painter.drawPixmap(QRect(xcoord, ycoord, dimens, dimens), stickman_anim[time / chsprite_every_n_frames % frames_per_anim]);
}

Stickman::~Stickman()
{

}

