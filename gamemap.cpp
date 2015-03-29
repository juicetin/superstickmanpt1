#include "gamemap.h"

GameMap::GameMap()
{

}

Background GameMap::getBackground()
{
    return m_background;
}

Stickman GameMap::getStickman()
{
    return m_stickman;
}

QPixmap GameMap::getBackgroundImage()
{
    return m_bg_img;
}

QPixmap * GameMap::getStickmanAnimations()
{
    return m_stickman_animations;
}

void GameMap::loadBackgroundImage(Settings * settings)
{
    m_bg_img.load(settings->getElement(settings_background_tag).c_str());
}

GameMap::~GameMap()
{

}

