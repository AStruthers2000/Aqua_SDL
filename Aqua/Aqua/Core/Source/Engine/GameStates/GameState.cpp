
#include "GameState.h"
#include <memory>
#include <iostream>

#include "GameSubState.h"
#include "Actor/Actor.h"
#include "Component/C_Render.h"
//#include "Game.h"

namespace AquaEngine
{
    GameState::~GameState()
    {
        for(const auto& actor : actors_)
        {
            RemoveActor(actor);
        }
    }

    void GameState::BeginPlay()
    {
        //i dont think anything needs to be here
    }

    void GameState::HandleInput(SDL_Event& event)
    {
        //something will probably be in here...
    }

    void GameState::Tick(float delta_time)
    {
        updating_actors_ = true;
        for(const auto& actor : actors_)
        {
            actor->Tick(delta_time);
        }

        updating_actors_ = false;
        for(const auto& actor : pending_actors_)
        {
            actors_.emplace_back(actor);

            //TODO: i dont think calling begin play should be here 2...
            actor->BeginPlay();
        }
        pending_actors_.clear();

        std::vector<Actor*> dead_actors;
        for(const auto& actor : actors_)
        {
            if(actor->GetActorState() == Actor::EDead)
            {
                dead_actors.emplace_back(actor);
            }
        }

        for(const auto& actor : dead_actors)
        {
            delete actor;
        }
    }

    void GameState::Render(SDL_Renderer* renderer)
    {
        for(const auto& render : render_components)
        {
            render->Draw(renderer);
        }
    }

    void GameState::AddActor(Actor* actor)
    {
        if(updating_actors_)
        {
            pending_actors_.emplace_back(actor);
        }
        else
        {
            actors_.emplace_back(actor);

            //TODO: i dont think calling begin play should be here...
            actor->BeginPlay();
        }
    }
    
    void GameState::RemoveActor(const Actor* actor)
    {
        if(!TryEraseActor(&actors_, actor))
        {
            if(!TryEraseActor(&pending_actors_, actor))
            {
                std::cerr << "GameState.h: Tried to delete actor that doesn't exist in either actors or pending_actors" << std::endl;
            }
        }
    }

    bool GameState::TryEraseActor(std::vector<Actor*>* list, const Actor* actor)
    {
        bool actor_found = false;
        
        size_t i;
        for(i = 0; i < list->size(); i++)
        {
            if((*list)[i] == actor)
            {
                actor_found = true;
                break;
            }
        }
        if(actor_found)
        {
            list->erase(list->begin() + static_cast<long long>(i));
            delete actor;
            return true;
        }

        return false;
    }
    

    void GameState::SetSubState(std::unique_ptr<GameSubState> substate)
    //void GameState::SetSubState(GameSubState* substate)
    {
        current_substate = std::move(substate);
        //TODO: probably shouldn't call begin play from here...
        current_substate->BeginPlay();
        //current_substate = substate;
    }
    
    void GameState::ClearSubState()
    {
        //delete current_substate;
        current_substate = nullptr;
    }

    void GameState::RegisterRendererComponent(C_Render* render_component)
    {
        const int draw_order = render_component->GetDrawOrder();
        auto iter = render_components.begin();
        for ( ; iter != render_components.end(); ++iter)
        {
            if (draw_order < (*iter)->GetDrawOrder())
            {
                break;
            }
        }

        // Inserts element before position of iterator
        render_components.insert(iter, render_component);
    }
}
