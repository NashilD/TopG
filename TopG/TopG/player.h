#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class player : public QObject, public QGraphicsPixmapItem
{
public:
    player();
};

#endif // PLAYER_H
