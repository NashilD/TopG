#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "target.h"
#include "gamewindow.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>
#include <QTimer>

class Level;

class projectile : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    projectile(double a, double f, Level *l, GameWindow *gw);
    void setAngle(double angle);
    void setForce(double force);
public slots:
    void move();

private:
    bool mousePressed;
    QPointF startPoint;
    QPointF endPoint;
    double angle;
    double force;
    double step_x, step_y;
    QTimer* timer;
    Level *currentlevel;
    GameWindow *gamewindow;
    int count;
};

#endif // PROJECTILE_H
