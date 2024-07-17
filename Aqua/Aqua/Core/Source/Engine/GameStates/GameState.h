#pragma once

#include <SDL.h>
#include "../Game.h"

class Game;

class GameState
{
public:
    GameState(Game* game) : game_manager(game) {}
    virtual ~GameState() = default;

    virtual void BeginPlay() = 0;
    virtual void HandleInput(SDL_Event& event) = 0;
    virtual void Tick(float delta_time) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

protected:
    Game* game_manager;
};
