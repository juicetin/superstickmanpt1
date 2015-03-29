#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <QPixmap>

#include "background.h"
#include "stickman.h"
#include "settings.h"

class GameMap
{
public:
    class Builder;
    GameMap();
    ~GameMap();

    Background getBackground();
    Stickman getStickman();
    QPixmap getBackgroundImage();
    QPixmap * getStickmanAnimations();
    void loadBackgroundImage(Settings * settings);


private:
    Background m_background;
    Stickman m_stickman;
    QPixmap m_bg_img;
    QPixmap * m_stickman_animations;

    GameMap (const Background m_background, Stickman m_stickman,
             const QPixmap m_bg_img, QPixmap * m_stickman_animations) :
        m_background(m_background), m_stickman(m_stickman),
    m_bg_img(m_bg_img), m_stickman_animations(m_stickman_animations){}
};

class GameMap::Builder
{
private:
    Background m_background;
    Stickman m_stickman;
    QPixmap m_bg_img;
    QPixmap * m_stickman_animations;

public:
    Builder& setBackground (const Background background)
    {
        this->m_background = background;
        return * this;
    }

    Builder& setStickman (const Stickman stickman)
    {
        this->m_stickman = stickman;
        return * this;
    }

    Builder& setBackgroundImage (const QPixmap bg_img)
    {
        this->m_bg_img = bg_img;
        return * this;
    }

    Builder& setStickmanAnimations (QPixmap * stickman_animations)
    {
        this->m_stickman_animations = stickman_animations;
        return * this;
    }

    GameMap build()
    {
        return GameMap(this->m_background, this->m_stickman, this->m_bg_img, this->m_stickman_animations);
    }
};

#endif // MAPBUILDER_H
