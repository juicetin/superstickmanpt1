#include "background.h"

void Background::render (QPainter &painter, unsigned int time, QPixmap bg, Settings * settings)
{

    int height = strtol(settings->getElement("window_height").c_str(),0,10);
    int width = strtol(settings->getElement("window_width").c_str(),0,10);

    //CONFIG VARIABLE Uglier solution than std::stoi. Qtcreator is missing it...
    int velocity = strtol(settings->getElement("start_v").c_str(),0,10);

    //Determine movement of background using time elapsed
    int move = time * velocity;
    if (move > width)
        move = move % width;
    
    //Draw two scrolling identical images to create illusion of infinite background
    painter.drawPixmap(QRect(width-move, 0, width, height), bg);
    painter.drawPixmap(QRect(-move,0,width,height), bg);
}

Background::~Background()
{

}

