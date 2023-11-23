#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "level.h"


GameWindow::GameWindow()
{
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
    QGraphicsTextItem *startMessage = new QGraphicsTextItem("Click to start the game");
    QFont font;
    font.setPixelSize(20); // Set the font size as needed
    startMessage->setFont(font);
    startMessage->setPos(396, 307);

    scene->addItem(startMessage);
}

void GameWindow::FinLevel()
{
    QGraphicsTextItem* FinishMessage = new QGraphicsTextItem("Finsihed with level" +QString::number(Current_Level));
    QFont font;
    font.setPixelSize(20); // Set the font size as needed
    FinishMessage->setFont(font);
    FinishMessage->setPos(396, 307);
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

    if (Started = true)
    {
        Current_Level = 1;
        Remaing_shots = 3;
        QGraphicsTextItem* textLevel = new QGraphicsTextItem("Level "+ QString::number(Current_Level));
        textLevel->setFont(QFont("times",16));
        textLevel->setPos(10,610);
        textLevel->setDefaultTextColor(Qt::black);
        QGraphicsTextItem* textShots = new QGraphicsTextItem("Shots remaining "+ QString::number(Remaing_shots));
        textShots->setFont(QFont("times",16));
        textShots->setPos(800,610);
        textLevel->setDefaultTextColor(Qt::black);

        scene->addItem(textLevel);
        scene->addItem(textShots);

        Player = new player();
        Player->setPos(10,295);
        Player->setFlag(QGraphicsItem::ItemIsFocusable);
        Player-> setFocus();
        scene->addItem(Player);

        //Level L(Current_Level,this);
        L = new Level(1,this);
        trajectory *trajectoryPath = new trajectory();
        trajectoryPath->setZValue(1);
        scene->addItem(trajectoryPath);
        installEventFilter(trajectoryPath);
        scene->update();


        //target T(10,305,80,80);
    }

}
