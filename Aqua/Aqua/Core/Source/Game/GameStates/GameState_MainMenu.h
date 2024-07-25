#pragma once
#include "GameState_Overworld.h"


class GameState_MainMenu : public AquaEngine::GameState
{
public:
    explicit GameState_MainMenu(AquaEngine::Game* game, const std::string& name)
        : GameState(game, name)
    {
    }

    ~GameState_MainMenu() override;

    void BeginPlay() override;
    void HandleInput(SDL_Event& event) override;
    void Tick(float delta_time) override;
    void Render(SDL_Renderer* renderer) override;
};
