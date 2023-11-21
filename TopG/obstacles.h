#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "target.h"

class Obstacles : public target
{
public:
    Obstacles(int X, int Y, int Width, int Height);
    int GetPosX() override;
    void SetPosX(int) override;
    int GetPosY() override;
    void SetPosY(int) override;
    int GetWidth() override;
    void SetWidth(int) override;
    int GetHeight() override;
    void SetHeight(int) override;
    bool GetStatus() override;
    void SetStatus(bool) override;

private:
    int OPosX, OPosY, OWidth, OHeight;
    bool OHitStatus;
};

#endif // OBSTACLES_H
