#include "projectile.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>

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
    angle = (double)angle - 0.05;
    y =  y + force *  qSin(qDegreesToRadians(angle));
    x =  x + force  * qCos(qDegreesToRadians(angle));
    setPos(x, y);
}


void projectile::setAngle(double angle)
{
    this->angle = angle;
}

void projectile::setForce(double force)
{
    this->force = force;
}
