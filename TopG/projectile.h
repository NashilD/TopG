#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "gamewindow.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>
#include <QTimer>
#include <QVector>
#include "obstacles.h"

class target;


class projectile : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    projectile(double a, double f, QVector<target*> &TVec, GameWindow *gw);
    void setAngle(double angle);
    void setForce(double force);
public slots:
    void move();

private:
    bool finLevel;
    QPointF startPoint;
    QPointF endPoint;
    double angle;
    double force;
    double step_x, step_y;
    QTimer* timer;
    GameWindow *gamewindow;
    QVector<target*> Ptargets;
};

#endif // PROJECTILE_H
