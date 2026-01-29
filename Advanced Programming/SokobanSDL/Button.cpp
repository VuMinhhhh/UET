#include "Button.h"

Button::Button()
{}

Button::~Button()
{
    SDL_DestroyTexture(texture);
}

Button::Button(int x, int y, int w, int h, const char* path, SDL_Renderer* ren)
{
    renderer = ren;

    SDL_Surface* tempSurface = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    destRect = {x, y, w, h};

}

void Button::SetPos(int x, int y)
{
    destRect.x = x;
    destRect.y = y;
}

void Button::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
