#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "target.h"
#include "obstacles.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    Bool Game_over;
    int GetShots();
    void SetShots(int);
    int GetLevel();
    void SetShots(int);
private:
    Ui::GameWindow *ui;
    int Current_Level;
    target targets;
    Obstacles obstacles;
    int Remaing_shots;
};
#endif // GAMEWINDOW_H

Class Level {

    private:
int LevelDiffcultiy;

    public : 
void SetLevelDIF (int LevelDIf) {

    LevelDIF=LevelDiffcultiy;
}

int getLevelDif()
{
    return LevelDiffcultiy;
}

void setTarget();
void SetObstacles();
void IncreaseDiffculity();



