#include "obstacles.h"

Obstacles::Obstacles(int x, int y, int width, int height) : QObject(), QGraphicsPixmapItem()
{
    OPosX = x;
    OPosY = y;
    OWidth = width;
    OHeight = height;
    OHitStatus = false;

    QPixmap obstacle("");
    obstacle = obstacle.scaledToHeight(height);
    obstacle = obstacle.scaledToWidth(width);
    setPixmap(obstacle);
    setPos(x,y);
}

int Obstacles::GetPosX()
{
    return OPosX;
}

void Obstacles::SetPosX(int NewX)
{
    OPosX = NewX;
}

int Obstacles::GetPosY()
{
    return OPosY;
}

void Obstacles::SetPosY(int NewY)
{
    OPosY = NewY;
}

int Obstacles::GetWidth()
{
    return OWidth;
}

void Obstacles::SetWidth(int NewWidth)
{
    OWidth = NewWidth;
}

int Obstacles::GetHeight()
{
    return OHeight;
}

void Obstacles::SetHeight(int NewHeight)
{
    OHeight = NewHeight;
}

bool Obstacles::GetStatus()
{
    return OHitStatus;
}

void Obstacles::SetStatus(bool NewStatus)
{
    OHitStatus = NewStatus;
}
