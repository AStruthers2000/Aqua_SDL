#include "GameSubState_FishingHook.h"
#include "GameState_FishingBattle.h"

#include <iostream>
#include "Game.h"

GameSubState_FishingHook::~GameSubState_FishingHook()
{
    std::cout << "Destroying fishing game sub state" << std::endl;
}

void GameSubState_FishingHook::BeginPlay()
{
    //GameState_Overworld::BeginPlay();
    std::cout << "Loading fishing quick time event" << std::endl;
}

void GameSubState_FishingHook::HandleInput(SDL_Event& event)
{
    //GameState_Overworld::HandleInput(event);

    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f)
    {
        //ExitSubstate();
        game_manager->ChangeState(std::make_unique<GameState_FishingBattle>(game_manager, "Fishing Battle"));
    }

    //handle fishing-specific input
}

void GameSubState_FishingHook::Tick(float delta_time)
{
    //GameState_Overworld::Tick(delta_time);

    //update fishing-specific logic
}

void GameSubState_FishingHook::Render(SDL_Renderer* renderer)
{
    //GameState_Overworld::Render(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    const SDL_Rect rect = {50, 50, 50, 50};
    SDL_RenderFillRect(renderer, &rect);
}
