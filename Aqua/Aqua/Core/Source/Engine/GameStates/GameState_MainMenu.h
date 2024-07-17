#pragma once

#include "GameState.h"

class GameState_MainMenu : public GameState
{
public:
    GameState_MainMenu(Game* game)
        : GameState(game)
    {
    }

    ~GameState_MainMenu();

    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
