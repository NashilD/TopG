#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include <QObject>
class target : public QObject, public QGraphicsPixmapItem
{
public:
    target(int X, int Y, int Width, int Height);
    int GetPosX();
    void SetPosX(int);
    int GetPosY();
    void SetPosY(int);
    int GetWidth();
    void SetWidth(int);
    int GetHeight();
    void SetHeight(int);
    bool GetStatus();
    void SetStatus(bool);
private:
    int TPosX, TPosY, TWidth, THeight;
    bool THitStatus;
};

#endif // TARGET_H
