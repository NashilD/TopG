#include "target.h"
#include "projectile.h"
#include "gamewindow.h"

target::target(int X, int Y, int Width, int Height)
{
    TPosX = X;
    TPosY = Y;
    TWidth = Width;
    THeight = Height;
    THitStatus = false;

    QPixmap Emoji(":/images/Emoji target.jpg");
    Emoji = Emoji.scaledToHeight(Height);
    Emoji = Emoji.scaledToWidth(Width);
    setPixmap(Emoji);
    setPos(X,Y);
}

int target::GetPosX()
{
    return TPosX;
}

void target::SetPosX(int NewX)
{
    TPosX = NewX;
}

int target::GetPosY()
{
    return TPosY;
}

void target::SetPosY(int NewY)
{
    TPosY = NewY;
}

int target::GetWidth()
{
    return TWidth;
}

void target::SetWidth(int NewWidth)
{
    TWidth = NewWidth;
}

int target::GetHeight()
{
    return THeight;
}

void target::SetHeight(int NewHeight)
{
    THeight = NewHeight;
}

bool target::GetStatus()
{
    return this->THitStatus;
}

void target::SetStatus(bool NewStatus)
{
    this->THitStatus = NewStatus;
}
