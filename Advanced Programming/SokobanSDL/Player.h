#pragma once

#include "Game.h"

class Player
{
public:
    Player(class Game* g);
    void Move(int x, int y);
    void Draw(SDL_Renderer* renderer);
    void getpos();
    void SetPos(int x, int y);
private:
    int direction;
    void SetDirection(int x, int y);
    Vec2 pos;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    class Game* game;
};
