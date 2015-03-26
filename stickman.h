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
#include "constants.h"

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
