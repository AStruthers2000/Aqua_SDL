
#include "Actor.h"
#include "Component/Component.h"
#include "Math/Vector.h"

namespace AquaEngine
{
    Actor::Actor(GameState* game_state) :  game_state_(game_state)
    {
        state_ = EActive;
        position_ = {0, 0};
        scale_ = {1, 1};
        rotation_ = 0;
    }

    void Actor::Tick(float delta_time)
    {
        if(state_ == EActive)
        {
            TickComponents(delta_time);
            TickActor(delta_time);
        }
    }

    void Actor::TickComponents(float delta_time)
    {
        for(const auto& component : components_)
        {
            component->TickComponent(delta_time);
        }
    }

    void Actor::AddComponent(Component* component)
    {
        if(components_.empty())
        {
            components_.push_back(component);
        }
        else
        {
            size_t i;
            for(i = 0; i < components_.size(); i++)
            {
                if(components_[i]->GetUpdateOrder() >= component->GetUpdateOrder())
                {
                    break;
                }
            }
            components_.insert(components_.begin() + static_cast<long long>(i), component);
        }
    }

    void Actor::RemoveComponent(const Component* component)
    {
        delete component;
    }
}
