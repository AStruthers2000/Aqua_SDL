#pragma once
#include "GameStates/GameSubState.h"

class GameSubState_FishingHook : public AquaEngine::GameSubState
{
public:
    explicit GameSubState_FishingHook(AquaEngine::Game* game, GameState* parent)
        : GameSubState(game, parent)
    {
    }

    ~GameSubState_FishingHook() override;
    
    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
