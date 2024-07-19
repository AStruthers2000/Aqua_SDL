#pragma once

#include <vector>

#include "Math/Vector.h"


namespace AquaEngine
{
    class Component;
    class Actor
    {
    public:
        enum State
        {
            EActive,
            EPaused,
            EDead
        };

        Actor(class GameState* game_state);
        virtual ~Actor() = default;

        ///non-overridable
        virtual void Tick(float delta_time) final;
        virtual void TickComponents(float delta_time) final;

        virtual void TickActor(float delta_time) = 0;

        void AddComponent(Component* component);
        void RemoveComponent(const Component* component);

    private:
        State state_;
        Vector2<float> position_;
        Vector2<float> scale_;
        float rotation_;

        std::vector<Component*> components_;
        GameState* game_state_;
    };
}
