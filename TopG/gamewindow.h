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
    void SetLevel(int);
    void displayStartMessage();
    void FinLevel();

protected:
    void mousePressEvent(QMouseEvent* event) override;

    QGraphicsScene* scene;
    QGraphicsView* view;
private:
    int Current_Level;
    target* targets;
    Obstacles* obstacles;
    int Remaing_shots;
    bool Started;
};
#endif // GAMEWINDOW_H