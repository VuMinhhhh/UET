#include "Game.h"

bool Game::Init(const char* title)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems Initialised!..." << endl;
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if(window)
        {
            cout << "Window created!" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }
        if( !(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0))
            {
                cout << "Mixer initialised!" << endl;
            }
        isRunning = true;
        bool MenuQuit = false;
        Menu = LoadTexture("Assets/Sprite/menu.png");

        StartButton = new Button{260, 360, 2* TILE_SIZE, 2 * TILE_SIZE, "Assets/Sprite/StartButton.png", renderer};
        QuitButton = new Button{100, 480, 2* TILE_SIZE, 2 * TILE_SIZE, "Assets/Sprite/QuitButton.png", renderer};
        MusicButton = new Button{420, 480, 2* TILE_SIZE, 2 * TILE_SIZE, "Assets/Sprite/MusicStartButton.png", renderer};

        gMusic = Mix_LoadMUS( "Assets/Song/Music0.mp3" );
        Mix_PlayMusic( gMusic, -1 );

        while(!MenuQuit)
        {
            SDL_Point mousePosition;
            SDL_Event event;
            SDL_Rect startButtonRect = {260, 360, 2 * TILE_SIZE, 2 * TILE_SIZE};
            SDL_Rect quitButtonRect = {100, 480, 2 * TILE_SIZE, 2 * TILE_SIZE};
            SDL_Rect musicButtonRect = {420, 480, 2 * TILE_SIZE, 2 * TILE_SIZE};
            SDL_RenderCopy(renderer, Menu, NULL, NULL);
            StartButton->draw(renderer);
            QuitButton->draw(renderer);
            MusicButton->draw(renderer);
            SDL_RenderPresent(renderer);

            if (SDL_WaitEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        MenuQuit = true;
                        isRunning = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
                            if (SDL_PointInRect(&mousePosition, &startButtonRect)) {
                                MenuQuit = true;
                                cout << "Enter Game State" << endl;
                                break;
                            } else if (SDL_PointInRect(&mousePosition, &quitButtonRect)) {
                                MenuQuit = true;
                                isRunning = false;
                                break;
                            } else if (SDL_PointInRect(&mousePosition, &musicButtonRect)) {
                                if( Mix_PlayingMusic() == 0 )
                                {
                                    MusicCount = MusicCount % 8;
                                    string tmp = "Assets/Song/Music" + to_string(MusicCount) + ".mp3";
                                    MusicButton->texture = LoadTexture("Assets/Sprite/MusicStartButton.png");
                                    const char* path = tmp.c_str();
                                    gMusic = Mix_LoadMUS( path );
                                    Mix_PlayMusic( gMusic, -1 );
                                    break;
                                }
                                else
                                {
                                    if( Mix_PausedMusic() == 1 ){
                                            Mix_ResumeMusic();
                                            MusicButton->texture = LoadTexture("Assets/Sprite/MusicStartButton.png");
                                            break;
                                    } else {
                                        Mix_PauseMusic();
                                        MusicButton->texture = LoadTexture("Assets/Sprite/MusicStopButton.png");
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            MenuQuit = true;
                        }
                        break;
                }
            }
        }
        SDL_DestroyTexture(Menu);
        delete StartButton;
        delete QuitButton;
        delete MusicButton;

        Mix_PauseMusic();

        manager = new LevelManager();
        manager->LoadLevel();
        //function button

        QuitButton = new Button{3 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/QuitButton.png", renderer};
        MusicButton = new Button{4 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/MusicOffButton.png", renderer};
        NextSongButton = new Button{5 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/NextSongButton.png", renderer};
        PreviousLevelButton = new Button{6 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/PreviousLevelButton.png", renderer};
        NextLevelButton = new Button{7 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/NextLevelButton.png", renderer};
        ReplayButton = new Button{8 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE, "Assets/Sprite/ReplayButton.png", renderer};

        //Load music
        gMusic = Mix_LoadMUS( "Assets/SoundEffect/1.wav" );

        //Load sound effects
        gNewLevel = Mix_LoadWAV( "Assets/SoundEffect/NewLevel.mp3" );
        gWallHit = Mix_LoadWAV( "Assets/SoundEffect/WallHit.mp3" );
        gBoxHit = Mix_LoadWAV( "Assets/SoundEffect/BoxHit.wav" );

        WallTexture = LoadTexture("Assets/Sprite/wall.png");
        GroundTexture = LoadTexture("Assets/Sprite/ground.png");
        BoxTexture = LoadTexture("Assets/Sprite/box.png");
        GoalTexture = LoadTexture("Assets/Sprite/goal.png");
        YouWin = LoadTexture("Assets/Sprite/YouWin.jpg");

        player = new Player(this);

        InitLevel();

        return true;

    }
    isRunning = false;
    return false;
}

void Game::GameLoop()
{
    while(isRunning)
    {
        HandleEvents();
        Update();
        Draw();
    }
}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_Point mousePosition;
    if(SDL_WaitEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                player->Move(1, 0);
                break;
            case SDLK_LEFT:
                player->Move(-1, 0);
                break;
            case SDLK_DOWN:
                player->Move(0, 1);
                break;
            case SDLK_UP:
                player->Move(0, -1);
                break;
            break;
            }
        }
        SDL_Rect quitButtonRect = {3 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        SDL_Rect musicButtonRect = {4 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        SDL_Rect nextSongButtonRect = {5 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        SDL_Rect previousLevelButtonRect = {6 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        SDL_Rect nextLevelButtonRect = {7 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
        SDL_Rect replayButtonRect = {8 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT) {
                SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
                if (SDL_PointInRect(&mousePosition, &quitButtonRect)) {
                    isRunning = false;
                } else if (SDL_PointInRect(&mousePosition, &musicButtonRect)) {
                    if( Mix_PlayingMusic() == 0 )
                    {
                        MusicCount = MusicCount % 8;
                        string tmp = "Assets/Song/Music" + to_string(MusicCount) + ".mp3";
                        MusicButton->texture = LoadTexture("Assets/Sprite/MusicOnButton.png");
                        const char* path = tmp.c_str();
                        gMusic = Mix_LoadMUS( path );
                        Mix_PlayMusic( gMusic, -1 );
                    }
                    else
                    {
                        if( Mix_PausedMusic() == 1 ){
                            MusicButton->texture = LoadTexture("Assets/Sprite/MusicOnButton.png");
                            if(MusicCount == 0) {
                                gMusic = Mix_LoadMUS( "Assets/Song/Music1.mp3" );
                                MusicCount++;
                                Mix_PlayMusic( gMusic, -1 );
                            } else {
                            Mix_ResumeMusic();
                            }
                        } else {
                            Mix_PauseMusic();
                            MusicButton->texture = LoadTexture("Assets/Sprite/MusicOffButton.png");
                        }
                    }
                } else if(SDL_PointInRect(&mousePosition, &nextSongButtonRect))
                {
                    Mix_HaltMusic();
                    MusicCount = (MusicCount) % 8 + 1;
                    string tmp = "Assets/Song/Music" + to_string(MusicCount) + ".mp3";
                    const char* path = tmp.c_str();
                    gMusic = Mix_LoadMUS( path );
                    Mix_PlayMusic( gMusic, -1 );
                } else if(SDL_PointInRect(&mousePosition, &previousLevelButtonRect))
                {
                    GoToPreviousLevel();
                } else if(SDL_PointInRect(&mousePosition, &nextLevelButtonRect))
                {
                    GoToNextLevel();
                } else if(SDL_PointInRect(&mousePosition, &replayButtonRect))
                {
                    DestroyBoxes();
                    InitLevel();
                    Mix_PlayChannel( -1, gWallHit, 0 );
                }
            }
        }
    }

    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_ESCAPE])
    {
        isRunning = false;
    }
}

void Game::Update()
{

}

void Game::Draw()
{
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    if(manager->GetCurrentLevel() == 0)
    {
        ReplayButton = new Button{8 * TILE_SIZE, 0, 2 * TILE_SIZE, 2 * TILE_SIZE, "Assets/Sprite/ReplayButton.png", renderer};ReplayButton->draw(renderer);
        SDL_Rect replayButtonRect = {8 * TILE_SIZE, 0, 2 * TILE_SIZE, 2 * TILE_SIZE};
        SDL_Event event;
        SDL_Point mousePosition;
        SDL_RenderCopy(renderer, YouWin, NULL, NULL);
        ReplayButton->draw(renderer);
        SDL_RenderPresent(renderer);
        while(SDL_WaitEvent(&event))
        {
            SDL_RenderPresent(renderer);
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
                    if(SDL_PointInRect(&mousePosition, &replayButtonRect)) {GoToNextLevel();break;}
                }
            }
        }
        return;
    }

    for(int row = 0; row < TILE_ROWS; row++)
        {
            for(int col = 0; col < TILE_COLS; col++)
            {
                SDL_Rect destRect = {col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                if(manager->LevelMap[col][row] == 'x')
                {
                    SDL_RenderCopy(renderer, WallTexture, NULL, &destRect);
                }
                else if(manager->LevelMap[col][row] == 'g')
                {
                    SDL_RenderCopy(renderer, GoalTexture, NULL, &destRect);
                }
                else
                {
                    SDL_RenderCopy(renderer, GroundTexture, NULL, &destRect);
                }
            }
        }

    for(auto b : boxes)
    {
        SDL_RenderCopy(renderer, BoxTexture, NULL, b->GetRect());
    }
    QuitButton->draw(renderer);
    MusicButton->draw(renderer);
    NextSongButton->draw(renderer);
    NextLevelButton->draw(renderer);
    PreviousLevelButton->draw(renderer);
    ReplayButton->draw(renderer);

    player->Draw(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    // Free music
    Mix_FreeChunk( gNewLevel );
    Mix_FreeChunk( gWallHit );
    Mix_FreeChunk( gBoxHit );
    Mix_FreeMusic( gMusic );

    // Free texture
    SDL_DestroyTexture(WallTexture);
    SDL_DestroyTexture(GroundTexture);
    SDL_DestroyTexture(BoxTexture);
    SDL_DestroyTexture(GoalTexture);
    SDL_DestroyTexture(StartButton->texture);
    SDL_DestroyTexture(QuitButton->texture);
    SDL_DestroyTexture(MusicButton->texture);
    SDL_DestroyTexture(NextSongButton->texture);
    SDL_DestroyTexture(NextLevelButton->texture);
    SDL_DestroyTexture(PreviousLevelButton->texture);
    SDL_DestroyTexture(ReplayButton->texture);
    SDL_DestroyTexture(YouWin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
}

SDL_Texture* Game::LoadTexture(const char* path)
{
    SDL_Surface* tempSurface = IMG_Load(path);
    if(tempSurface == NULL)
        cout << "Failed to load surface: " << IMG_GetError() << endl;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if(texture == NULL)
        cout << "Failed to convert to texture" << SDL_GetError() << endl;
    SDL_FreeSurface(tempSurface);
    return texture;
}

bool Game::HitWall(int x, int y)
{
    if(manager->LevelMap[x][y] == 'x') {
        Mix_PlayChannel( -1, gWallHit, 0 );
        return true;
    }
    return false;
}

bool Game::CanPushBox(Box* box, int x, int y)
{
    if(HitWall(x, y))
        return false;

    for(auto b : boxes)
    {
        if(b == box)
            continue;
        else if(x == b->GetPos().x && y == b->GetPos().y) {
            Mix_PlayChannel( -1, gWallHit, 0 );
            return false;
        }
    }
    Mix_PlayChannel( -1, gBoxHit, 0 );
    return true;
}

bool Game::BoxUpdated(int moveX, int moveY, int pX, int pY)
{
    Box* BoxToPush = NULL;
    for(auto b : boxes)
    {
        if(pX == b->GetPos().x && pY == b->GetPos().y)
        {
            BoxToPush = b;
            break;
        }
    }
    if(BoxToPush != NULL)
    {
        int toPushX = pX + moveX;
        int toPushY = pY + moveY;
        if(CanPushBox(BoxToPush, toPushX, toPushY))
        {
            bool InGoal = HitGoal(toPushX, toPushY);
            if(InGoal)
                cout << toPushX << " " << toPushY << " " << "Goal Hit!" << endl;
            BoxToPush->Update(toPushX, toPushY, InGoal);
            if(ALlGoalsCompleted())
            {
                cout << "All goals completed!" << endl;
                GoToNextLevel();
                return false;
            }
        }
        else
            return false;
    }
    return true;
}

bool Game::HitGoal(int x, int y)
{
    return manager->LevelMap[x][y] == 'g';
}

bool Game::ALlGoalsCompleted()
{
    for(auto b : boxes)
    {
        if(!b->GetInGoal())
            return false;
    }
    return true;
}

void Game::DestroyBoxes()
{
    for(auto &b : boxes)
        delete b;
    boxes.erase(boxes.begin(), boxes.end());
}

void Game::InitLevel()
{
    for(int row = 0; row < TILE_ROWS; row++)
    {
        for(int col = 0; col < TILE_COLS; col++)
        {
            if(manager->LevelMap[col][row] == 'p')
            {
                player->SetPos(col, row);
            }
            else if(manager->LevelMap[col][row] == 'b')
            {
                boxes.emplace_back(new Box(col, row));
            }
        }
    }
}

void Game::GoToNextLevel()
{
    DestroyBoxes();

    manager->UpdateNextLevel();
    manager->LoadLevel();

    Mix_PlayChannel( -1, gNewLevel, 0 );

    InitLevel();
}

void Game::GoToPreviousLevel()
{
    if(manager->GetCurrentLevel() == 1)
        return;

    DestroyBoxes();

    manager->UpdatePreviousLevel();
    manager->LoadLevel();

    Mix_PlayChannel( -1, gNewLevel, 0 );

    InitLevel();
}

