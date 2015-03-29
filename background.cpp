#include "background.h"

Background::Background()
{

}

void Background::render (QPainter &painter, unsigned int time, QPixmap bg, Settings * settings)
{

    int height = strtol(settings->getElement(config_window_height).c_str(),0,10);
    int width = strtol(settings->getElement(config_window_width).c_str(),0,10);

    //CONFIG VARIABLE Uglier solution than std::stoi. Qtcreator is missing it...
    int velocity = strtol(settings->getElement(stickman_start_v).c_str(),0,10);

    //Determine movement of background using time elapsed
    int move = time * velocity;
    if (move > width)
        move = move % width;
    
    //Draw two scrolling identical images to create illusion of infinite background
    painter.drawPixmap(QRect(width-move, 0, width, height), bg);
    painter.drawPixmap(QRect(-move,0,width,height), bg);
}

void Background::loadBackgroundImage(QPixmap bg_img, Settings * settings)
{
    bg_img.load(settings->getElement(settings_background_tag).c_str());
}

Background::~Background()
{

}

