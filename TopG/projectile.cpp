#include "projectile.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>
#include <QMessageBox>
#include <QGraphicsItem>

projectile::projectile(double a, double f) : QObject(), QGraphicsPixmapItem()
{
    QPixmap projectilePixmap(":/images/pngimg.com - cannonball_PNG2.png");
    projectilePixmap = projectilePixmap.scaledToHeight(80);
    projectilePixmap = projectilePixmap.scaledToWidth(80);
    setPixmap(projectilePixmap);
    force = f;
    angle = a;
    move();
}

void projectile::move()
{
    angle = (double)angle + 0.5;
    y =  force *  qSin(qDegreesToRadians(angle)) * 2;
    x =  force  * qCos(qDegreesToRadians(angle)) * 2 - 0.5 * 9.8 * 4;
    setPos(x, y);

    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (target))
        {
            QMessageBox::information(nullptr,"Info","Hit");
        }
    }
}

void projectile::setAngle(double angle)
{
    this->angle = angle;
}

void projectile::setForce(double force)
{
    this->force = force;
}
