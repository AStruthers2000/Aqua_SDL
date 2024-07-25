#pragma once
#include "GameStates/GameState.h"


class GameState_FishingBattle : public AquaEngine::GameState
{
public:
    explicit GameState_FishingBattle(AquaEngine::Game* game, const std::string& name)
        : GameState(game, name)
    {
    }

    ~GameState_FishingBattle() override;
    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
