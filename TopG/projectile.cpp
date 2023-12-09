#include "projectile.h"
#include "level.h"
#include "gamewindow.h"
#include "obstacles.h"
#include <QTimer>
#include <QPixmap>
#include <qmath.h>
#include <QGraphicsItem>


projectile::projectile(double a, double f, QVector<target*> &TVec, GameWindow *gw) : QObject(), QGraphicsPixmapItem(), Ptargets(TVec)
{
    QPixmap projectilePixmap(":/images/pngimg.com - cannonball_PNG2.png");
    projectilePixmap = projectilePixmap.scaledToHeight(55);
    projectilePixmap = projectilePixmap.scaledToWidth(55);
    setPixmap(projectilePixmap);
    force = f;
    angle = a;
    gamewindow = gw;
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

    QList<QGraphicsItem *> collidning_item= collidingItems();
    for(int i =0; i< collidning_item.size() ; i++)
    {
        if(typeid (*(collidning_item[i]))==typeid (Obstacles))
        {
            gamewindow->scene->removeItem(collidning_item[i]);
            gamewindow->scene->removeItem(this);
            delete collidning_item[i];
            delete this;
            return;
        }

        if(typeid (*(collidning_item[i]))==typeid (target))
        {
            gamewindow->AddCount();
            gamewindow->scene->removeItem(collidning_item[i]);
            gamewindow->scene->removeItem(this);

            if (gamewindow->GetCount() == Ptargets.size())
            {
                if (gamewindow->getCurrentLevel() == 10)
                {
                    Ptargets.clear();
                    gamewindow->DoneGame();
                }
                else
                {
                    Ptargets.clear();
                    gamewindow->FinLevel();
                }
            }
            delete collidning_item[i];
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
