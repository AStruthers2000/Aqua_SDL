#pragma once

import std;
#include <SDL.h>
//#include "GameSubState.h"

class GameSubState;
class Game;

class GameState
{
public:
    GameState(Game* game) : game_manager(game), current_substate(nullptr) {}
    virtual ~GameState() = default;

    virtual void BeginPlay() = 0;
    virtual void HandleInput(SDL_Event& event) = 0;
    virtual void Tick(float delta_time) = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;

    void SetSubState(std::unique_ptr<GameSubState> substate)
    {
        current_substate = std::move(substate);
    }
    void ClearSubState()
    {
        current_substate = nullptr;
    }

protected:
    Game* game_manager;
    std::unique_ptr<GameSubState> current_substate;
};
