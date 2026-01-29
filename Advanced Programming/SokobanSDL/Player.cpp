#include "Player.h"

Player::Player(Game* g)
{
    game = g;
    texture = game->LoadTexture("Assets/Sprite/player.png");
    direction = 0;
    pos.x = 0;
    pos.y = 0;
    destRect = {pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    srcRect = {0, 0, TILE_SIZE, TILE_SIZE};
}

void Player::Move(int x, int y)
{
    SetDirection(x, y);

    int newPos_x = pos.x + x;
    int newPos_y = pos.y + y;

    if(game->HitWall(newPos_x, newPos_y))
    {
        cout << newPos_x << " " << newPos_y << endl;
        cout << "HIT WALL" << endl;
        return;
    }

    if(!game->BoxUpdated(x, y, newPos_x, newPos_y))
    {
        cout << newPos_x << " " << newPos_y << endl;
        cout << "HIT BOX" << endl;
        return;
    }

    pos.x = newPos_x;
    pos.y = newPos_y;

    destRect.x = pos.x * TILE_SIZE;
    destRect.y = pos.y * TILE_SIZE;

}

void Player::Draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void Player::getpos()
{
    cout << destRect.x << " " << destRect.y << endl;
}

void Player::SetDirection(int x, int y)
{
    if(x > 0)
    {
        direction = 0;
    }
    else if(x < 0)
    {
        direction = 2;
    }
    else if(y > 0)
    {
        direction = 1;
    }
    else if(y < 0)
    {
        direction = 3;
    }

    srcRect.x  = direction * TILE_SIZE;
}

void Player::SetPos(int x, int y)
{
    direction = 0;
    pos.x = x;
    pos.y = y;
    destRect = {pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    srcRect = {0, 0, TILE_SIZE, TILE_SIZE};
}
