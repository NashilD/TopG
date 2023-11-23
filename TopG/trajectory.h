#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>

class trajectory : public QGraphicsPixmapItem, public QObject
{
    Q_OBJECT
public:
    trajectory();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
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

#endif // TRAJECTORY_H
