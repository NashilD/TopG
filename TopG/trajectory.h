#ifndef TRAJECTORY_H
#define TRAJECTORY_H

class trajectory
{
private:
    double force;
    double angle;
    double distance;
public:
    double GetDistance();
    void setAngle(double);
    void setForce(double);


};

#endif // TRAJECTORY_H