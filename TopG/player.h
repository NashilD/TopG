#ifndef PLAYER_H
#define PLAYER_H
#include "GameWindow.h"
#include "trajectory.h"

class player : public GameWindow, public trajectory
{
private:
    double Angle;
    double Force;
    int Max_Shots;
public:
    void SetAngle(double);
    void SetForce(double);
    void SetMax_shot(int);
    int GetMax_shot();


};


#endif // PLAYER_H