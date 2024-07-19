#pragma once
#include "../../Engine/GameStates/GameSubState.h"

class GameSubState_PauseMenu : public AquaEngine::GameSubState
{
public:
    GameSubState_PauseMenu(AquaEngine::Game* game, GameState* parent)
        : GameSubState(game, parent)
    {
    }

    ~GameSubState_PauseMenu() override;
    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
