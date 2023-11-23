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
#include "target.h"
#include "obstacles.h"
#include "player.h"
#include "projectile.h"

class Level;
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
    void addToScene(QGraphicsPixmapItem* temp);
    QGraphicsScene* scene;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    int Current_Level;
    int Remaing_shots;
    bool Started;
    player* Player;
    Level* L;
    double Angle;
    double Force;
   // trajectory *tajectoryPath;
};
#endif // GAMEWINDOW_H



