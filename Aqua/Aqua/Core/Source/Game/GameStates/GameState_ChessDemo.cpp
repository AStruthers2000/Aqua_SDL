#include "GameState_ChessDemo.h"

#include <iostream>

#include "GameSubState_PauseMenu.h"

GameState_ChessDemo::~GameState_ChessDemo()
{
    std::cout << "Destroying chess demo" << std::endl;
}

void GameState_ChessDemo::BeginPlay()
{
    std::cout << "Starting chess demo" << std::endl;
}

void GameState_ChessDemo::HandleInput(SDL_Event& event)
{
    if(current_substate)
    {
        std::cout << "Valid chess demo substate, handling input there instead" << std::endl;
        current_substate->HandleInput(event);
    }
    else
    {
        if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                std::cout << "Pressing escape:\n\tPausing game" << std::endl;

                if(!current_substate)
                {
                    SetSubState(std::make_unique<GameSubState_PauseMenu>(game_manager, this));
                }
                break;
            default: break;
            }
        }
    }
}

void GameState_ChessDemo::Tick(float delta_time)
{
}

void GameState_ChessDemo::Render(SDL_Renderer* renderer)
{
    //Render chess demo
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, 255);
    SDL_RenderClear(renderer);

    //add chess demo rendering code

    //if there is a substate, render that on top of the current state
    if(current_substate)
    {
        current_substate->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}
