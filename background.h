#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPointF>

class Background
{
public:
    Background(int time) : m_time(time) {}
    ~Background();

    void render(QPainter &painter, unsigned int time, QPixmap bg);

private:
    Background();
    int m_time;
};

#endif // BACKGROUND_H
