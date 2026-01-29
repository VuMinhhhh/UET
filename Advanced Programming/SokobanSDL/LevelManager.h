#pragma once

#include "Utils.h"
#include <fstream>
#include <string>

class LevelManager
{
public:
    void LoadLevel();
    void UpdateNextLevel();
    void UpdatePreviousLevel();
    int GetCurrentLevel();
    char LevelMap[TILE_ROWS][TILE_COLS] = {0};
private:
    std::fstream LevelFile;
    int currentLevel = 1;
};
