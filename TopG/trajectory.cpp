#include "trajectory.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>

trajectory::trajectory()
{
    mousePressed = false;
    angle = 0;
    force = 0;
}
trajectory::trajectory(double a, double f) : QObject(), QGraphicsPixmapItem()
{
    QPixmap trajectoryPixmap(":/images/cannonball_PNG2.png");
    trajectoryPixmap = trajectoryPixmap.scaledToHeight(40);
    trajectoryPixmap = trajectoryPixmap.scaledToWidth(40);
    setPixmap(trajectoryPixmap);
    force = f;
    angle = a;
    QTimer * move_timer = new QTimer(this);
    connect (move_timer,SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

}

void trajectory::move()
{
    y =  y + force * qsin(qDegreesToRadians(angle));
    x =  x + force  * qcos(qDegreesToRadians(angle));
    angle = (double)angle - 0.05;
    setPos(x()+x, y()+y);

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
