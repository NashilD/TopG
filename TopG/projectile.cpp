#include "projectile.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>

projectile::projectile()
{
    angle = 0;
    force = 0;
}
projectile::projectile(double a, double f) : QObject(), QGraphicsPixmapItem()
{
    QPixmap projectilePixmap(":/images/cannonball_PNG2.png");
    projectilePixmap = projectilePixmap.scaledToHeight(40);
    projectilePixmap = projectilePixmap.scaledToWidth(40);
    setPixmap(projectilePixmap);
    force = f;
    angle = a;
    QTimer * move_timer = new QTimer(this);
    connect (move_timer,SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

}

void projectile::move()
{
    y =  y + force * qsin(qDegreesToRadians(angle));
    x =  x + force  * qcos(qDegreesToRadians(angle));
    angle = (double)angle - 0.05;
    setPos(x(), y());

}


void projectile::setAngle(double angle)
{
    this->angle = angle;
}

void projectile::setForce(double force)
{
    this->force = force;
}
