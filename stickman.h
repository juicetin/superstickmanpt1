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
    Stickman() {}
    ~Stickman();

    void render(QPainter &painter, unsigned int time, QPixmap stickman_anim[], Settings * settings);

    void setBackground(const QPixmap &pixmap);

    void loadSprites(QPixmap * stickman_anim, Settings * settings);

private:
    int m_time;
};

#endif // STICKMAN_H
