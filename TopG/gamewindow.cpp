#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "level.h"
#include "trajectory.h"
#include "projectile.h"
#include <QMessageBox>

GameWindow::GameWindow()
{
    projCreated = false;
    Done = false;
    scene = new QGraphicsScene;
    count =0;
    LevelDiff = 3;
    Current_Level = 1;
    Remaing_shots = 10;

    scene->setSceneRect(0, 0, 1000, 650);
    setFixedSize(1000,650);
    setWindowTitle("Canonfire Strike");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);
    displayStartMessage();
}

int GameWindow::GetShots()
{
    return Remaing_shots;
}

void GameWindow::displayStartMessage()
{
    Started = false;
    QGraphicsTextItem *startMessage = new QGraphicsTextItem("Use the left and right arrows to control the force.\nUse the up and down arrows to control the angle.\nPress P to fire.\nClick to start the game.");
    startMessage->setFont(QFont("times",25));
    startMessage->setPos(180, 275);
    startMessage->setDefaultTextColor(Qt::black);
    scene->addItem(startMessage);
}

void GameWindow::FinLevel()
{
    scene->clear();
    QGraphicsTextItem* FinishMessage = new QGraphicsTextItem("Finished with level " +QString::number(Current_Level));
    FinishMessage->setFont(QFont("times",50));
    FinishMessage->setPos(198,307);
    FinishMessage->setDefaultTextColor(Qt::green);
    count =0;
    L->Vobstacles.clear();
    Current_Level++;
    Remaing_shots = 10;
    if ((Current_Level == 4) || (Current_Level ==7))
    {
        LevelDiff = 1;
    }
    else
        LevelDiff++;
    finLevel = true;
    scene->addItem(FinishMessage);
}

void GameWindow::DoneGame()
{
    scene->clear();
    L->Vobstacles.clear();
    Done = true;
    QGraphicsTextItem* DoneGame = new QGraphicsTextItem("Congratulations! You've completed Canonfire Strike!\nThank you for playing our game.\ncredit:\nNashil Dayanand\nMaha Shakshuki\nEman Hegab\nMariam Gaballah\nOptions:\nPress 1 to replay the game.\nPress 2 to quit the game.");
    DoneGame->setFont(QFont("times",25));
    DoneGame->setPos(198,100);
    DoneGame->setDefaultTextColor(Qt::green);
    scene->addItem(DoneGame);
}

void GameWindow::Lost()
{
    scene->clear();
    QGraphicsTextItem* LostMessage = new QGraphicsTextItem("You lost at level " +QString::number(Current_Level));
    LostMessage->setFont(QFont("times",50));
    LostMessage->setPos(198,307);
    LostMessage->setDefaultTextColor(Qt::red);
    scene->addItem(LostMessage);
}

void GameWindow::addToScene(QGraphicsPixmapItem *temp)
{
    scene->addItem(temp);
}

void GameWindow::AddCount()
{
    count++;
}

int GameWindow::GetCount()
{
    return count;
}

int GameWindow::getCurrentLevel()
{
    return Current_Level;
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    if (scene->items().size() > 0)
    {
        scene->clear();
        Started = true;
    }

    if (Started == true)
    {
        Force = 0;
        Angle = 0;

        finLevel = false;

        textLevel = new QGraphicsTextItem("Level "+ QString::number(Current_Level));
        textLevel->setFont(QFont("times",16));
        textLevel->setPos(10,610);
        textLevel->setDefaultTextColor(Qt::black);

        textShots = new QGraphicsTextItem("Shots remaining "+ QString::number(Remaing_shots));
        textShots->setFont(QFont("times",16));
        textShots->setPos(800,610);
        textShots->setDefaultTextColor(Qt::black);

        TextAngle = new QGraphicsTextItem("Angle: " + QString::number(Angle));
        TextAngle->setFont(QFont("times",16));
        TextAngle->setPos(207,610);
        TextAngle->setDefaultTextColor(Qt::black);

        TextForce = new QGraphicsTextItem("Force: " + QString::number(Force));
        TextForce->setFont(QFont("times",16));
        TextForce->setPos(407,610);
        TextForce->setDefaultTextColor(Qt::black);

        Player = new player();
        Player->setPos(10,295);
        scene->addItem(Player);

        scene->addItem(textLevel);
        scene->addItem(textShots);
        scene->addItem(TextAngle);
        scene->addItem(TextForce);

        L = new Level(Current_Level,this, LevelDiff);
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Up)
    {
        Angle += 5;
        TextAngle->setPlainText("Angle: " + QString::number(Angle));
    }
    else if(event -> key() == Qt::Key_Down)
    {
        Angle -= 5;
        TextAngle->setPlainText("Angle: " + QString::number(Angle));
    }
    if(event -> key() == Qt::Key_Right)
    {
        Force += 5;
        TextForce->setPlainText("Force: " + QString::number(Force));
    }
    if(event -> key() == Qt::Key_Left)
    {
        if(Force != 0)
         {
            Force -=5;
            TextForce->setPlainText("Force: " + QString::number(Force));
         }
    }
    if (event->key() == Qt::Key_P)
     {
         scene->removeItem(textShots);
         Remaing_shots--;
         textShots = new QGraphicsTextItem("Shots remaining "+ QString::number(Remaing_shots));
         textShots->setFont(QFont("times",16));
         textShots->setPos(800,610);
         textShots->setDefaultTextColor(Qt::black);
         scene->addItem(textShots);
         Proj = new projectile(Angle,Force, L->Vtargets, this);
         scene->addItem(Proj);
     }

    if (Done == true)
     {
         if (event->key() == Qt::Key_1)
         {
            scene->clear();
            projCreated = false;
            Done = false;
            count =0;
            LevelDiff = 1;
            Current_Level = 1;
            Remaing_shots = 10;
            displayStartMessage();
         }
         else if (event->key() == Qt::Key_2)
         {
           QCoreApplication::quit();
         }

     }

}

