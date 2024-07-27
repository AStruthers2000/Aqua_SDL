#pragma once

#include <memory>
#include <vector>

//#include "Math/Bounds.h"
#include "Math/Transform.h"
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
        Vector2<float> GetActorPosition() const { return transform_.GetTransformPosition(); }
        const Vector2<float>* GetActorPositionRef() const { return transform_.GetTransformPositionRef(); }

        template <typename T>
        std::shared_ptr<T> TryGetComponent() const;
        //Bounds GetActorBounds() const { return bounds_; }

        void SetActorState(State new_state) { state_ = new_state; }
        void SetActorPosition(const Vector2<float>& new_position) { transform_.SetTransformPosition(new_position); }
        //void SetActorBounds(const Bounds& new_bounds) { bounds_ = new_bounds; }

    private:
        State state_;
        Transform transform_;
        //Bounds bounds_;

        std::vector<std::shared_ptr<Component>> components_;
        GameState* game_state_;
    };

    template <typename T>
    std::shared_ptr<T> Actor::TryGetComponent() const
    {
        for(const auto& component : components_)
        {
            if(const auto success = std::dynamic_pointer_cast<T>(component))
            {
                return success;
            }
        }
        return nullptr;
    }
}
