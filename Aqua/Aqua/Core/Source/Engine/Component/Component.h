#pragma once

#include "Actor/Actor.h"
namespace AquaEngine
{
    class Component
    {
    public:
        Component(Actor* owner, int update_order = 100) : owner_(owner), update_order_(update_order) {}
        virtual ~Component() = default;

        virtual void TickComponent(float delta_time) = 0;
        int GetUpdateOrder() const { return update_order_; }

    protected:
        Actor* owner_;
        int update_order_;
    
    };
}