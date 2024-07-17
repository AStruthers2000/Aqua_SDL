
#include "GameState_Overworld.h"

#include "GameState_MainMenu.h"

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
    
    if(event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RETURN:
            std::cout << "Pressing enter:\n\tNothing happens..." << std::endl;
            break;
        case SDLK_f:
            std::cout << "Pressing f:\n\tStarted fishing" << std::endl;
            break;
        case SDLK_ESCAPE:
            std::cout << "Pressing escape:\n\tExiting from overworld" << std::endl;
            //game_manager->PopGameState();
            game_manager->ChangeState(std::make_unique<GameState_MainMenu>(game_manager));
            break;
        default: break;
        }
    }
    
}

void GameState_Overworld::Tick(float delta_time)
{
}

void GameState_Overworld::Render(SDL_Renderer* renderer)
{
    //Render overworld
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}