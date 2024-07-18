#include "GameState_Overworld.h"

#include "../Game.h"
#include "GameSubState.h"
#include "GameState_MainMenu.h"
#include "GameSubState_FishingHook.h"
#include "GameSubState_PauseMenu.h"

GameState_Overworld::~GameState_Overworld()
{
    std::cout << "Destroying overworld game state" << std::endl;
}

void GameState_Overworld::BeginPlay()
{
    std::cout << "Loading overworld game state" << std::endl;
}

void GameState_Overworld::HandleInput(SDL_Event& event)
{
    if(current_substate)
    {
        std::cout << "Valid overworld substate, handling input there instead" << std::endl;
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
            case SDLK_f:
                std::cout << "Pressing f:\n\tStarted fishing" << std::endl;
                SetSubState(std::make_unique<GameSubState_FishingHook>(game_manager, this));
                break;
            case SDLK_ESCAPE:
                std::cout << "Pressing escape:\n\tPausing game" << std::endl;
                //game_manager->PopGameState();
                //game_manager->ChangeState(std::make_unique<GameState_MainMenu>(game_manager));
                if(!current_substate)
                {
                    SetSubState(std::make_unique<GameSubState_PauseMenu>(game_manager, this));
                }
                else
                {
                    std::cout <<"\tCan't pause during fishing minigame" << std::endl;
                }
                break;
            default: break;
            }
        }
    }
}

void GameState_Overworld::Tick(float delta_time)
{
    if(current_substate)
    {
        current_substate->Tick(delta_time);
    }

    //Overworld logic here
}

void GameState_Overworld::Render(SDL_Renderer* renderer)
{
    //Render overworld
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

    //add overworld rendering code

    //if there is a substate, render that on top of the current state
    if(current_substate)
    {
        current_substate->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}


