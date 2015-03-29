#include "stickman.h"

void Stickman::render(QPainter &painter, unsigned int time, QPixmap stickman_anim[], Settings * settings)
{
    int height = std::atoi(settings->getElement(config_window_height).c_str());

    std::string size = settings->getElement(size_tag); //CONFIG VARIABLE

    int start_pos = std::atoi(settings->getElement(stickman_start_x).c_str());  //CONFIG VARIABLE

    int xcoord = start_pos;
    int ycoord;
    int dimens;

    int base_y = 0.81 * height;
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
        extra_size = height/25;
        ycoord = base_y - extra_size;
        dimens = base_dimens + extra_size;
    }

    else if (strcmp(size.c_str(), size_large) == 0)
    {
        extra_size = height/10;
        ycoord = base_y - extra_size;
        dimens = base_dimens + extra_size;
    }

    else if (strcmp(size.c_str(), size_giant) == 0)
    {
        extra_size = height/5;
        ycoord = base_y - extra_size;
        dimens = base_dimens + extra_size;
    }

    int velocity = std::atoi(settings->getElement(stickman_start_v).c_str());    //CONFIG VARIABLE
    int chsprite_every_n_frames = 7-velocity/2;
    int frames_per_anim = 6;

    painter.drawPixmap(QRect(xcoord, ycoord, dimens, dimens), stickman_anim[time / chsprite_every_n_frames % frames_per_anim]);
}

void Stickman::loadSprites(QPixmap * stickman_anim, Settings * settings)
{
    int size = std::atoi(settings->getElement(stickman_anim_length).c_str());

    for (int i = 0; i < size; ++i)
    {
        std::stringstream mario_frame;
        mario_frame << i+1;
        std::string mario_file;
        mario_file.append(settings->getElement(stickman_folder).c_str())
                .append("/")
                .append(settings->getElement(stickman_character).c_str())
                .append(mario_frame.str())
                .append(settings->getElement(image_type).c_str());
        stickman_anim[i].load(mario_file.c_str());
    }
}

Stickman::~Stickman()
{

}

