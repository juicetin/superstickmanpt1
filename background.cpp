#include "background.h"

void Background::render (QPainter &painter, unsigned int time, QPixmap bg)
{
	int velocity = 2;	//CONFIG VARIABLE
    int move = time * 2 * velocity;
    if (move > 1000)
        move = move % 1000;
    
    painter.drawPixmap(QRect(1000-move, 0, 1000, 600), bg);
    painter.drawPixmap(QRect(-move,0,1000,600), bg);
}

Background::~Background()
{

}

