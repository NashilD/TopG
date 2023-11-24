#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "target.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>
#include <QTimer>

class projectile : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   projectile(double a, double f);
    void setAngle(double angle);
    void setForce(double force);
    bool GetCollision();
public slots:
    void move();

private:
    bool mousePressed;
    QPointF startPoint;
    QPointF endPoint;
    double angle;
    double force;
    double step_x, step_y;
    bool TargetDown;
    QTimer* timer;
};

#endif // PROJECTILE_H
