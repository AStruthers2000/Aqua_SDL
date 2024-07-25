#pragma once

#include <memory>
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

        virtual void BeginPlay() = 0;
        virtual void TickActor(float delta_time) = 0;

        void AddComponent(const std::shared_ptr<Component>& component);
        void RemoveComponent(const std::shared_ptr<Component>& component);

        State GetActorState() const { return state_; }
        GameState* GetActorWorld() const { return game_state_; }
        Vector2<float> GetActorPosition() const { return position_; }

        void SetActorPosition(const Vector2<float>& new_position) { position_ = new_position; }
        void SetActorState(State new_state) { state_ = new_state; }

    private:
        State state_;
        Vector2<float> position_;
        Vector2<float> scale_;
        float rotation_;

        std::vector<std::shared_ptr<Component>> components_;
        GameState* game_state_;
    };
}
