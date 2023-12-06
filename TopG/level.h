#ifndef LEVEL_H
#define LEVEL_H
#include "target.h"
#include "obstacles.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QVector>
#include <random>

class GameWindow;
class target;
class Obstacles;
class Level : public QObject
{
public:
    Level(int num, GameWindow* GW);
    void SetLevelDIF (int LevelDIf);
    int getLevelDif();
    void setTarget();
    void SetObstacles();
    void IncreaseDiffculity();
    QVector<target*> Vtargets;
    QVector<Obstacles*> Vobstacles;
    target *t;
private:
    int LevelDifficulty, level, lowerBoundX, upperBoundX, lowerBoundY, upperBoundY;
    GameWindow* gw;
};

#endif // LEVEL_H
