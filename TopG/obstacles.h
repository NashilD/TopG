#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "target.h"

class Obstacles
{
public:
    Obstacles(int X, int Y, int Width, int Height);
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
    int OPosX, OPosY, OWidth, OHeight;
    bool OHitStatus;
};

#endif // OBSTACLES_H
