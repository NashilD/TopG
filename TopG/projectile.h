#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "target.h"
#include "level.h"
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>
#include <QTimer>

class target;
class projectile : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   projectile(double a, double f);
    void setAngle(double angle);
    void setForce(double force);
    void move();

private:
    bool mousePressed;
    QPointF startPoint;
    QPointF endPoint;
    double angle;
    double force;
    double x, y;
};

#endif // PROJECTILE_H
