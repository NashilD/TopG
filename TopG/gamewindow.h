#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QTimer>
#include <QVector>
#include "player.h"

class Level;
class projectile;
class target;

class GameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    GameWindow();
    ~GameWindow();
    bool Game_over;
    int GetShots();
    void SetShots(int);
    int GetLevel();
    void displayStartMessage();
    void FinLevel();
    void DoneGame();
    void Lost();
    void addToScene(QGraphicsPixmapItem* temp);
    void AddCount();
    int GetCount();
    int getCurrentLevel();
    QGraphicsScene* scene;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    int Current_Level, Remaing_shots, count, LevelDiff;
    bool Started, projCreated, finLevel, Done;
    player* Player;
    Level* L;
    double Angle;
    double Force;
    QGraphicsTextItem *TextForce;
    QGraphicsTextItem *TextAngle;
    QGraphicsTextItem* textLevel;
    QGraphicsTextItem* textShots;
    projectile * Proj;
};
#endif // GAMEWINDOW_H



