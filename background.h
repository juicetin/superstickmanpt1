#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPointF>
#include <string>
#include <cstdlib>

#include "settings.h"
#include "constants.h"

class Background
{
public:
    Background();
    ~Background();

    void render(QPainter &painter, unsigned int time, QPixmap bg, Settings * settings);
    void loadBackgroundImage(QPixmap bg_img, Settings * settings);

private:
    int m_time;
    QPixmap m_bg_img;
};

#endif // BACKGROUND_H
