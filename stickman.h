#ifndef STICKMAN_H
#define STICKMAN_H

#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <string>
#include <iostream>
#include <sstream>
#include <string>

#include "settings.h"

#define SMALL 0
#define NORMAL 1
#define LARGE 2
#define GIANT 3

class Stickman
{
public:
    Stickman(int time) : m_time(time) {}

    ~Stickman();

    void render(QPainter &painter, unsigned int time, QPixmap stickman_anim[], Settings * settings);

    void setBackground(const QPixmap &pixmap);

private:
    Stickman();
    int m_time;
};

#endif // STICKMAN_H
