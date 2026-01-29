#pragma once

#include "Utils.h"

class Box
{
private:
    Vec2 pos;
    SDL_Rect destRect;
    bool inGoal;
public:
    Box(int x, int y);
    ~Box();
    void Update(int x, int y, bool complete);
    Vec2 GetPos();
    SDL_Rect* GetRect();
    bool GetInGoal();
};
