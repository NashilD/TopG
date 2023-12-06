#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "level.h"
#include "trajectory.h"
#include "projectile.h"
#include <QMessageBox>

GameWindow::GameWindow()
{
    Force = 0;
    Angle = 0;
    projCreated = false;
    scene = new QGraphicsScene;

    scene->setSceneRect(0, 0, 1000, 650);
    setFixedSize(1000,650);
    setWindowTitle("Game Name");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);

    displayStartMessage();
}

GameWindow::~GameWindow()
{
    //delete ui;
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
    finLevel = true;
    scene->addItem(FinishMessage);
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

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    if (scene->items().size() > 0)
    {
        scene->clear();
        Started = true;
    }

    if (Started == true)
    {
        Current_Level = 1;
        Remaing_shots = 10;

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

        L = new Level(Current_Level,this);
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
         Proj = new projectile(Angle,Force, L, this); // Create a new projectile

         scene->addItem(Proj);

         if ((Remaing_shots == 0) && (finLevel == false))
         {
            Lost();
         }
     }

}

