#pragma once
#include <SDL_events.h>
#include <SDL_render.h>
#include <vector>
#include <memory>

//#include "GameSubState.h"


namespace AquaEngine
{
    class Actor;
    class Game;
    class GameSubState;

    class GameState
    {
    public:
        GameState(Game* game) : game_manager(game), current_substate(nullptr), updating_actors_(false) {}
        virtual ~GameState() = default;

        virtual void BeginPlay() = 0;
        virtual void HandleInput(SDL_Event& event) = 0;
        virtual void Tick(float delta_time) = 0;
        virtual void Render(SDL_Renderer* renderer) = 0;


        
        void AddActor(Actor* actor);
        void RemoveActor(const Actor* actor);
        
        void SetSubState(std::unique_ptr<GameSubState> substate);
        //void SetSubState(GameSubState* substate);
        void ClearSubState();
        
    
    protected:
        Game* game_manager;
        std::unique_ptr<GameState> current_substate;
        //GameSubState* current_substate;
        std::vector<Actor*> actors_;

    private:
        
        bool updating_actors_;
        
        std::vector<Actor*> pending_actors_;
        bool TryEraseActor(std::vector<Actor*>* list, const Actor* actor);

       
    };
}
