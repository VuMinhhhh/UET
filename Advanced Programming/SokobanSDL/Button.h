#pragma once

#include "Utils.h"

class Button
{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
    bool selected = false;
    class Game* game;

    Button();
    Button(int x, int y, int w, int h, const char* path, SDL_Renderer* ren);
    ~Button();

    void SetPos(int x, int y);
    void draw(SDL_Renderer* renderer);
};
