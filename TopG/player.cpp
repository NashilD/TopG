#include "player.h"
#include "gamewindow.h"


player::player() : QObject(), QGraphicsPixmapItem()
{
    QPixmap playerPixmap(":/images/Canon.png");
    playerPixmap = playerPixmap.scaledToHeight(80);
    playerPixmap = playerPixmap.scaledToWidth(80);
    setPixmap(playerPixmap);
}
