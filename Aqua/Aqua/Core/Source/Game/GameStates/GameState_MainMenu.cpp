#include "GameState_MainMenu.h"

#include <iostream>
#include "Game.h"

GameState_MainMenu::~GameState_MainMenu()
{
    std::cout << "Destroying main menu game state" << std::endl;
}

void GameState_MainMenu::BeginPlay()
{
    std::cout << "Loading main menu game state" << std::endl;
}

void GameState_MainMenu::HandleInput(SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_RETURN)
        {
            std::cout << "Pressing enter:\n\tLoading overworld state" << std::endl;
            //transition to open world state
            game_manager->ChangeState(std::make_unique<GameState_Overworld>(game_manager));
        }
    }
}

void GameState_MainMenu::Tick(float delta_time)
{
    //main menu logic
}

void GameState_MainMenu::Render(SDL_Renderer* renderer)
{
    //Render main menu
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}