#include "trajectory.h"

trajectory::trajectory()
{
    mousePressed = false;
    angle = 0;
    force = 0;
}

void trajectory::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mousePressed = true;
    startPoint = event->pos();
    endPoint = startPoint;
    setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
}

void trajectory::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (mousePressed)
    {
        endPoint = event->scenePos();
        setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    }
}

void trajectory::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mousePressed = false;
    endPoint = event->scenePos();
    setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());

    double dx = endPoint.x() - startPoint.x();
    double dy = endPoint.y() - startPoint.y();

    force = qSqrt(dx * dx + dy * dy);
    angle = qAtan2(dy, dx);
}

void trajectory::setAngle(double angle)
{
    this->angle = angle;
}

void trajectory::setForce(double force)
{
    this->force = force;
}
