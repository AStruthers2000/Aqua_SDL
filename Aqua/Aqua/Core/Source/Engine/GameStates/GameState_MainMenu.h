#pragma once

#include "GameState.h"
#include "GameSubState.h"

class GameState_MainMenu : public GameState
{
public:
    explicit GameState_MainMenu(Game* game)
        : GameState(game)
    {
    }

    ~GameState_MainMenu() override;

    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
