#pragma once
#include "GameState.h"


namespace AquaEngine
{
    class GameSubState : public GameState
    {
    public:
        explicit GameSubState(Game* game, GameState* parent)
            : GameState(game), parent_state(parent)
        {
        }

        ~GameSubState() override = default;
        void BeginPlay() override = 0;
        void HandleInput(SDL_Event& event) override = 0;
        void Tick(float delta_time) override = 0;
        void Render(SDL_Renderer* renderer) override = 0;
    

    protected:

        
        void ExitSubstate() const
        {
            parent_state->ClearSubState();
        }
        
        GameState* parent_state;
    };
}
