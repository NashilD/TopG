#include "projectile.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>
#include <QGraphicsItem>

projectile::projectile(double a, double f) : QObject(), QGraphicsPixmapItem()
{
    QPixmap projectilePixmap(":/images/pngimg.com - cannonball_PNG2.png");
    projectilePixmap = projectilePixmap.scaledToHeight(55);
    projectilePixmap = projectilePixmap.scaledToWidth(55);
    setPixmap(projectilePixmap);
    force = f;
    angle = a;
    TargetDown = false;
    setPos(10,295);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(90);
    step_y =  0.1*force *  qSin(qDegreesToRadians(360-angle));
    step_x =  0.1*force  * qCos(qDegreesToRadians(360-angle));

}

void projectile::move()
{


    setPos(x()+step_x, y()+step_y);

    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (target))
        {
            TargetDown = true;
           scene()->removeItem(collidningitem[i]);
           scene()->removeItem(this);
           delete collidningitem[i];
            delete this;
            return;

        }
    }
    step_y+=0.49;
}

void projectile::setAngle(double angle)
{
    this->angle = angle;
}

void projectile::setForce(double force)
{
    this->force = force;
}

bool projectile::GetCollision()
{
    return TargetDown;
}
