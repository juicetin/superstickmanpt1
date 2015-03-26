#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPointF>
#include <string>
#include <cstdlib>

#include "settings.h"

class Background
{
public:
    Background(int time) : m_time(time) {}
    ~Background();

    void render(QPainter &painter, unsigned int time, QPixmap bg, Settings * settings);

private:
    Background();
    int m_time;
};

#endif // BACKGROUND_H
