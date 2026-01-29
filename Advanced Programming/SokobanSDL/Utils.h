#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

using namespace std;

const int TILE_SIZE = 64;
const int TILE_ROWS = 10;
const int TILE_COLS = 10;
const int SCREEN_WIDTH = TILE_SIZE * TILE_COLS;
const int SCREEN_HEIGHT = TILE_SIZE * TILE_ROWS;

class Vec2
{
public:
    int x;
    int y;
};
