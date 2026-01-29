#pragma once

#include "Utils.h"
#include "LevelManager.h"
#include "Player.h"
#include "Box.h"
#include "Button.h"
#include <vector>

class Game
{
public:
    bool Init(const char* path);
    void GameLoop();
    void clean();

    SDL_Texture* LoadTexture(const char* path);
    bool HitWall(int x, int y);
    bool HitBox(int x, int y);
    bool CanPushBox(Box* box, int x, int y);
    bool BoxUpdated(int moveX, int moveY, int pX, int pY);
private:
    void HandleEvents();
    void Update();
    void Draw();

    bool ALlGoalsCompleted();
    bool HitGoal(int x, int y);
    void DestroyBoxes();
    void InitLevel();
    void GoToNextLevel();
    void GoToPreviousLevel();

    bool isRunning;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* GroundTexture;
    SDL_Texture* WallTexture;
    SDL_Texture* BoxTexture;
    SDL_Texture* GoalTexture;
    SDL_Texture* Menu;
    SDL_Texture* YouWin;

    LevelManager* manager;
    class Player* player;
    vector<Box*> boxes;

    Mix_Music *gMusic = NULL;
    Mix_Chunk *gNewLevel = NULL;
    Mix_Chunk *gWallHit = NULL;
    Mix_Chunk *gBoxHit = NULL;
    int MusicCount = 0;

    Button* StartButton;
    Button* QuitButton;
    Button* MusicButton;
    Button* NextSongButton;
    Button* NextLevelButton;
    Button* PreviousLevelButton;
    Button* ReplayButton;
};


