#ifndef LEVEL_H
#define LEVEL_H
#include "target.h"
#include "obstacles.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class GameWindow;
class Level : public QObject
{
public:
    Level(int num, GameWindow* GW);
    void SetLevelDIF (int LevelDIf);
    int getLevelDif();
    void setTarget();
    void SetObstacles();
    void IncreaseDiffculity();
    target *t;
private:
    int LevelDifficulty;
    int level;
    GameWindow* gw;
};

#endif // LEVEL_H
