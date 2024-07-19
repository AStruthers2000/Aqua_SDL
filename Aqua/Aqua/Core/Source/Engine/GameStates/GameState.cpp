
#include "GameState.h"
#include <memory>
#include <iostream>

#include "GameSubState.h"
#include "Actor/Actor.h"
//#include "Game.h"

namespace AquaEngine
{
    
    void GameState::AddActor(Actor* actor)
    {
        if(updating_actors_)
        {
            pending_actors_.emplace_back(actor);
        }
        else
        {
            actors_.emplace_back(actor);
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
        //current_substate = substate;
    }
    
    void GameState::ClearSubState()
    {
        //delete current_substate;
        current_substate = nullptr;
    }

    
}