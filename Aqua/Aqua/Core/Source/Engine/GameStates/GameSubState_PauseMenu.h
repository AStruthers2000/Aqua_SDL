#pragma once
#include "GameSubState.h"

class GameSubState_PauseMenu : public GameSubState
{
public:
    GameSubState_PauseMenu(Game* game, GameState* parent)
        : GameSubState(game, parent)
    {
    }

    ~GameSubState_PauseMenu() override;
    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
