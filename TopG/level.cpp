#include "level.h"
#include "obstacles.h"
#include "gamewindow.h"

Level::Level(int num, GameWindow *GW, int LD)
{
    level = num;
    gw = GW;
    LevelDifficulty = LD;
    setTarget();
    SetObstacles();
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
    lowerBoundX = 75;
    upperBoundX = 800;
    lowerBoundY = 25;
    upperBoundY = 610;

    int X,Y;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution1(lowerBoundX, upperBoundX);
    std::uniform_int_distribution<int> distribution2(lowerBoundY, upperBoundY);


    if ((level >= 1) && (level <=3))
    {
         X = distribution1(gen);
         Y = distribution2(gen);
         t = new target(X,Y,80,80);
         gw->scene->addItem(t);
         Vtargets.push_back(t);
    }

    if ((level >= 4) && (level <=6))
    {
         for (int i = 0; i <2; i++)
         {
             X = distribution1(gen);
             Y = distribution2(gen);
             t = new target(X,Y,80,80);
             gw->scene->addItem(t);
             Vtargets.push_back(t);
         }
    }

    if ((level >= 7) && (level <=9))
    {
         for (int i = 0; i <3; i++)
         {
             X = distribution1(gen);
             Y = distribution2(gen);
             t = new target(X,Y,80,80);
             gw->scene->addItem(t);
             Vtargets.push_back(t);
         }
    }

    if ((level == 10))
    {
         for (int i = 0; i <4; i++)
         {
             X = distribution1(gen);
             Y = distribution2(gen);
             t = new target(X,Y,80,80);
             gw->scene->addItem(t);
             Vtargets.push_back(t);
         }
    }
}

void Level::SetObstacles()
{
    int count = -1;
    int X, Y;

    if ((level == 2) || (level == 5) || (level == 8))
    {
         for (int j = 0; j<Vtargets.size(); j++)
         {
             for (int i = 0; i < LevelDifficulty; i++)
             {
                 count = -1;
                 if (Vobstacles.empty())
                 {
                     X = Vtargets[j]->GetPosX() - 80;
                     Y = Vtargets[j]->GetPosY();
                     qDebug() << "j: " << j;
                 }
                 else
                 {
                     count++;
                     X = Vobstacles[count]->GetPosX();
                     Y = Vobstacles[count]->GetPosY() - 80;
                 }
                 Obstacles* obstacle = new Obstacles(X, Y, 80, 80);
                 gw->scene->addItem(obstacle);
                 Vobstacles.push_back(obstacle);
             }

             Vobstacles.clear();
         }

    }
    else if ((level == 3) || (level == 6) || (level == 9))
    {
         for (int j = 0; j<Vtargets.size(); j++)
         {
             count = -1;
             for (int i = 0; i < LevelDifficulty; i++)
             {
                 if (Vobstacles.empty())
                 {
                     X = Vtargets[j]->GetPosX() - 80;
                     Y = Vtargets[j]->GetPosY();
                 }
                 else
                 {
                     count++;
                     X = Vobstacles[count]->GetPosX();
                     Y = Vobstacles[count]->GetPosY() - 80;
                 }
                 Obstacles* obstacle = new Obstacles(X, Y, 80, 80);
                 gw->scene->addItem(obstacle);
                 Vobstacles.push_back(obstacle);
             }

             Vobstacles.clear();
         }

    }
    else if (level == 10)
    {
         for (int j = 0; j<Vtargets.size(); j++)
         {
             count = -1;
             for (int i = 0; i < LevelDifficulty; i++)
             {
                 if (Vobstacles.empty())
                 {
                     X = Vtargets[j]->GetPosX() - 80;
                     Y = Vtargets[j]->GetPosY();
                 }
                 else
                 {
                     count++;
                     X = Vobstacles[count]->GetPosX();
                     Y = Vobstacles[count]->GetPosY() - 80;
                 }
                 Obstacles* obstacle = new Obstacles(X, Y, 80, 80);
                 gw->scene->addItem(obstacle);
                 Vobstacles.push_back(obstacle);
             }

             Vobstacles.clear();
         }

    }
}
