#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPointF>
#include <QObject>

class trajectory : public QGraphicsLineItem, public QObject
{
public:
    trajectory();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void setAngle(double angle);
    void setForce(double force);

private:
    bool mousePressed;
    QPointF startPoint;
    QPointF endPoint;
    double angle;
    double force;
};

#endif // TRAJECTORY_H
