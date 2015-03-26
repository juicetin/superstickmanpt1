#include "background.h"

void Background::render (QPainter &painter, unsigned int time, QPixmap bg, Settings * settings)
{
    int velocity = strtol(settings->getElement("start_v").c_str(),0,10);    //CONFIG VARIABLE Uglier solution than std::stoi. Qtcreator is missing it...
    int move = time * 2 * velocity;
    if (move > 1000)
        move = move % 1000;
    
    painter.drawPixmap(QRect(1000-move, 0, 1000, 600), bg);
    painter.drawPixmap(QRect(-move,0,1000,600), bg);
}

Background::~Background()
{

}

