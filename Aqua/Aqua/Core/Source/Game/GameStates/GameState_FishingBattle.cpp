#include "GameState_FishingBattle.h"

#include "GameSubState_PauseMenu.h"
#include <iostream>

GameState_FishingBattle::~GameState_FishingBattle()
{
    std::cout << "Destroying fishing battle game state" << std::endl;
}

void GameState_FishingBattle::BeginPlay()
{
    std::cout << "Beginning fishing battle" << std::endl;
}

void GameState_FishingBattle::HandleInput(SDL_Event& event)
{
    if(current_substate)
    {
        std::cout << "Valid fishing substate, handling input there instead" << std::endl;
        current_substate->HandleInput(event);
    }
    else
    {
        if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
                std::cout << "Pressing enter:\n\tNothing happens..." << std::endl;
                break;
            case SDLK_ESCAPE:
                std::cout << "Pressing escape:\n\tPausing game" << std::endl;
                //SetSubState(new GameSubState_PauseMenu(game_manager, this));
                SetSubState(std::make_unique<GameSubState_PauseMenu>(game_manager, this));
                break;
            default: break;
            }
        }
    }
}

void GameState_FishingBattle::Tick(float delta_time)
{
    
}

void GameState_FishingBattle::Render(SDL_Renderer* renderer)
{
    //Render fish battle
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    //add fish battle rendering code
    

    //if there is a substate, render that on top of the current state
    if(current_substate)
    {
        current_substate->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}
