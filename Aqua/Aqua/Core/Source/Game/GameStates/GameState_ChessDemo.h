#pragma once
#include "GameStates/GameState.h"

class GameState_ChessDemo : public AquaEngine::GameState
{
public:
    explicit GameState_ChessDemo(AquaEngine::Game* game)
        : GameState(game)
    {
    }
    ~GameState_ChessDemo() override;
    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
  
};
