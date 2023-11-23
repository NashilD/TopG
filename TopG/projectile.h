#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>
#include <QTimer>

class projectile : public QGraphicsPixmapItem, public QObject
{
    Q_OBJECT
public:
   projectile(double a, double f);

    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
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
    QTimer* move_timer;
};

#endif // PROJECTILE_H
