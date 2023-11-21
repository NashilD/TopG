#ifndef TARGET_H
#define TARGET_H

class target
{
public:
    target(int X, int Y, int Width, int Height);
   virtual int GetPosX() = 0;
    virtual void SetPosX(int) = 0;
    virtual int GetPosY() = 0;
    virtual void SetPosY(int) = 0;
    virtual int GetWidth() = 0;
    virtual void SetWidth(int) = 0;
   virtual int GetHeight() = 0;
   virtual void SetHeight(int) = 0;
   virtual bool GetStatus() = 0;
   virtual void SetStatus(bool) = 0;
private:
    int TPosX, TPosY, TWidth, THeight;
    bool THitStatus;
};

#endif // TARGET_H
