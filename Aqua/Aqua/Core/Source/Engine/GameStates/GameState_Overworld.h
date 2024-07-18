﻿#pragma once
#include "GameState.h"
#include "GameSubState.h"

class GameState_Overworld : public GameState
{
public:
    explicit GameState_Overworld(Game* game)
        : GameState(game)//, current_substate(nullptr)
    {
    }

    ~GameState_Overworld() override;

    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
    
    
};
