#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class player : public QObject, public QGraphicsPixmapItem
{
private:
    double Angle;
    double Force;

public:
    player();
    player(double angle, double force);
    void SetAngle(double);
    void SetForce(double);
};

#endif // PLAYER_H
