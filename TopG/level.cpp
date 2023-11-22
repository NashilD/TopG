#include "level.h"
#include "gamewindow.h"

Level::Level(int num, GameWindow *GW)
{
    level = num;
    gw = GW;
    setTarget();
}

void Level::SetLevelDIF(int LevelDIf)
{
    LevelDifficulty = LevelDIf;
}

int Level::getLevelDif()
{
    return LevelDifficulty;
}

void Level::setTarget(){

    if (level == 1)
    {
        T = new target(396,295,80,80);
        gw->scene->addItem(T);
    }
}

void Level::SetObstacles(){

  //  Obstacles = obs;

}
void Level::IncreaseDiffculity()
{
    LevelDifficulty++;
}
