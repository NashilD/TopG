#include "gamewindow.h"
#include "trajectory.h"

Player::Player(int Level, int Shots)
{
    Angle = angle;
    Force = force;
    Max_Shots = max_shot;
}


int Player::GetMax_shot()
{
    return Max_Shots;
}
void Player::SetAngle(double angle )
{
    Angle = angle;
}
int Player::GetShots()
{
    return Remaing_shots;
}
void Player::SetMax_shot(int max_shot)
{
    Max_Shots = max_shot;
}
void Player::SetForce(double force)
{
    Force = force;

}