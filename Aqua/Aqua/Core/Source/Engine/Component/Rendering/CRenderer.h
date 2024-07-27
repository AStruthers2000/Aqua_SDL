#pragma once
#include <SDL_render.h>
#include "Component/Component.h"
#include "GameStates/GameState.h"
#include "Math/Bounds.h"

namespace AquaEngine
{
    class CRenderer : public Component
    {
    public:
        CRenderer(Actor* owner, int draw_order, const Vector2<float>& size)
            : Component(owner), draw_order_(draw_order)
        {
            owner->GetActorWorld()->RegisterRendererComponent(this);
            bounds_ = {owner->GetActorPositionRef(), size.x, size.y};
        }

        void TickComponent(float delta_time) override;
        virtual void Draw(SDL_Renderer* renderer) = 0;

        int GetDrawOrder() const { return draw_order_; }
        Bounds GetBounds() const { return bounds_; }

    protected:
        int draw_order_;

    private:
        Bounds bounds_;
    };
}
