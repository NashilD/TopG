#ifndef LEVEL_H
#define LEVEL_H
#include "target.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QVector>
#include <random>
#include "obstacles.h"


class GameWindow;
class target;

class Level : public QObject
{
public:
    Level(int num, GameWindow* GW, int LD);
    void SetLevelDIF (int LevelDIf);
    int getLevelDif();
    void setTarget();
    void SetObstacles();
    QVector<target*> Vtargets;
    QVector<Obstacles*> Vobstacles;
    target *t;
private:
    int LevelDifficulty, level, lowerBoundX, upperBoundX, lowerBoundY, upperBoundY;
    GameWindow* gw;
};

#endif // LEVEL_H
