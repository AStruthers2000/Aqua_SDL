#include "GameSubState_PauseMenu.h"

#include <iostream>

#include "GameState_MainMenu.h"
#include "Game.h"
#include <vector>
#include "Actor/Actor.h"

GameSubState_PauseMenu::~GameSubState_PauseMenu()
{
    std::cout << "Destroying pause menu sub state" << std::endl;

    for(const auto& actor : parent_state->GetActors())
    {
        actor->SetActorState(AquaEngine::Actor::EActive);
    }
}

void GameSubState_PauseMenu::BeginPlay()
{
    for(const auto& actor : parent_state->GetActors())
    {
        actor->SetActorState(AquaEngine::Actor::EPaused);
    }
}

void GameSubState_PauseMenu::HandleInput(SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_RETURN:
            game_manager->ChangeState(std::make_unique<GameState_MainMenu>(game_manager, "Main Menu"));
            break;
        case SDLK_ESCAPE:
            ExitSubstate();
        default: break;
        }
    }
}

void GameSubState_PauseMenu::Tick(float delta_time)
{

}

void GameSubState_PauseMenu::Render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BlendMode::SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
    constexpr SDL_Rect screen {0, 0, 800, 600};
    constexpr SDL_Rect menu {300, 100, 200, 400};
    SDL_RenderFillRect(renderer, &screen);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    SDL_RenderFillRect(renderer, &menu);
    
}
