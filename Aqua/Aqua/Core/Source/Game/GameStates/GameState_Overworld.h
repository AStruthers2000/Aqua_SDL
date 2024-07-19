#pragma once
#include "GameStates/GameState.h"


class GameState_Overworld : public AquaEngine::GameState
{
public:
    explicit GameState_Overworld(AquaEngine::Game* game)
        : GameState(game)//, current_substate(nullptr)
    {
    }

    ~GameState_Overworld() override;

    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
    
    
};
