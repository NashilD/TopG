#include "player.h"
#include "gamewindow.h"


player::player() : QObject(), QGraphicsPixmapItem()
{
    QPixmap playerPixmap(":/images/Canon.png");
    playerPixmap = playerPixmap.scaledToHeight(80);
    playerPixmap = playerPixmap.scaledToWidth(80);
    setPixmap(playerPixmap);
}

player::player(double angle, double force)
{
    Angle = angle;
    Force = force;
}

void player::SetAngle(double angle)
{
    Angle = angle;
}

void player::SetForce(double force)
{
    Force = force;
}
