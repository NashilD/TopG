#ifndef LEVEL_H
#define LEVEL_H


class Level
{
public:
    Level();
    void SetLevelDIF (int LevelDIf);
    int getLevelDif();
    void setTarget();
    void SetObstacles();
    void IncreaseDiffculity();
private:
    int LevelDifficulty;
    int Target; 
    int Obstacles; 
};

#endif // LEVEL_H
