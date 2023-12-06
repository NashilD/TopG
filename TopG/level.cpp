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

void Level::setTarget()
{
    lowerBoundX = 25;
    upperBoundX = 800;
    lowerBoundY = 10;
    upperBoundY = 610;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution1(lowerBoundX, upperBoundX);
    std::uniform_int_distribution<int> distribution2(lowerBoundY, upperBoundY);


    if ((level >= 1) && (level <=3))
    {
         int X = distribution1(gen);
         int Y = distribution2(gen);
         t = new target(X,Y,80,80);
         gw->scene->addItem(t);
         Vtargets.push_back(t);
    }

    if ((level >= 4) && (level <=6))
    {
         for (int i = 0; i <2; i++)
         {
             int X = distribution1(gen);
             int Y = distribution2(gen);
             t = new target(X,Y,80,80);
             gw->scene->addItem(t);
             Vtargets.push_back(t);
         }
    }

    if ((level >= 7) && (level <=10))
    {
         for (int i = 0; i <3; i++)
         {
             int X = distribution1(gen);
             int Y = distribution2(gen);
             t = new target(X,Y,80,80);
             gw->scene->addItem(t);
             Vtargets.push_back(t);
         }
    }
}

void Level::SetObstacles()
{
    lowerBoundX = 25;
    upperBoundX = 800;
    lowerBoundY = 10;
    upperBoundY = 610;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution1(lowerBoundX, upperBoundX);
    std::uniform_int_distribution<int> distribution2(lowerBoundY, upperBoundY);

    if ((level >= 2) && (level <=3))
    {
        for (int i = 0; i < level; i++ )
        {
         //int X = distribution1(gen);
         //int Y = distribution2(gen);
         //t = new target(X,Y,80,80);
         //gw->scene->addItem(t);
         //Vtargets.push_back(t);
        }
    }

}
void Level::IncreaseDiffculity()
{
    LevelDifficulty++;
}
