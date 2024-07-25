#pragma once
#include <SDL_events.h>
#include <SDL_render.h>
#include <vector>
#include <memory>
#include <string>

//#include "GameSubState.h"


namespace AquaEngine
{
    class CRenderer;
    class Actor;
    class Game;
    class GameSubState;

    class GameState
    {
    public:
        GameState(Game* game, std::string name) : game_manager(game), current_substate(nullptr), name_(std::move(name)),  updating_actors_(false) {}
        virtual ~GameState();

        virtual void BeginPlay();
        virtual void HandleInput(SDL_Event& event);
        virtual void Tick(float delta_time);
        virtual void Render(SDL_Renderer* renderer);


        
        void AddActor(const std::shared_ptr<Actor>& actor);
        void RemoveActor(const std::shared_ptr<Actor>& actor);
        std::vector<std::shared_ptr<Actor>> GetActors() { return actors_; }
        
        void SetSubState(std::unique_ptr<GameSubState> substate);
        //void SetSubState(GameSubState* substate);
        void ClearSubState();
        void RegisterRendererComponent(CRenderer* render_component);

    
    
    protected:
        Game* game_manager;
        std::unique_ptr<GameState> current_substate;
        //GameSubState* current_substate;
        

    private:
        std::string name_;
        bool updating_actors_;
        std::vector<std::shared_ptr<Actor>> actors_;
        std::vector<std::shared_ptr<Actor>> pending_actors_;
        bool TryEraseActor(std::vector<std::shared_ptr<Actor>>* list, const std::shared_ptr<Actor> actor);

    
        std::vector<CRenderer*> render_components;

       
    };
}
