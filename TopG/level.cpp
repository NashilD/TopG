#include "level.h"

Level::Level()
{

}

void Level::SetLevelDIF(int LevelDIf)
{
    LevelDifficulty = LevelDIf;
}

int Level::getLevelDif()
{
    return LevelDifficulty;
}

void Level::setTarget(int T){
    Target = T;
}

    void Level::SetObstacles(int obs){

        Obstacles = obs; 

    }
    void Level::IncreaseDiffculity()
{
        
    }
