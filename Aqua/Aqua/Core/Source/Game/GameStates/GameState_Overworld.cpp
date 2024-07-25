#include "GameState_Overworld.h"

#include <iostream>

#include "Game.h"
#include "Actor/Actor.h"
#include "GameSubState_FishingHook.h"
#include "GameSubState_PauseMenu.h"
#include "../Actors/ATest.h"

GameState_Overworld::~GameState_Overworld()
{
    std::cout << "Destroying overworld game state" << std::endl;

    //TODO: remove this deleting of actors from this class
    //for(const auto& actor : actors_)
    //{
    //    RemoveActor(actor);
    //}
}

void GameState_Overworld::BeginPlay()
{
    std::cout << "Loading overworld game state" << std::endl;
    //AddActor(new ATest(this));
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
                //SetSubState(new GameSubState_FishingHook(game_manager, this));
                SetSubState(std::make_unique<GameSubState_FishingHook>(game_manager, "Fishing Hook", this));
                break;
            case SDLK_ESCAPE:
                std::cout << "Pressing escape:\n\tPausing game" << std::endl;
                //game_manager->PopGameState();
                //game_manager->ChangeState(std::make_unique<GameState_MainMenu>(game_manager));
                if(!current_substate)
                {
                    //SetSubState(new GameSubState_PauseMenu(game_manager, this));
                    SetSubState(std::make_unique<GameSubState_PauseMenu>(game_manager, "Pause Menu", this));
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

    //TODO: remove this updating of actors from this class
    //for(const auto& actor : actors_)
    //{
    //    actor->Tick(delta_time);
    //}
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


