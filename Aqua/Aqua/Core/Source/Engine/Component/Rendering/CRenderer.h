#pragma once
#include <SDL_render.h>
#include "Component/Component.h"
#include "GameStates/GameState.h"

namespace AquaEngine
{
    class CRenderer : public Component
    {
    public:
        CRenderer(Actor* owner, int draw_order)
            : Component(owner), draw_order_(draw_order)
        {
            owner->GetActorWorld()->RegisterRendererComponent(this);
        }

        void TickComponent(float delta_time) override;
        virtual void Draw(SDL_Renderer* renderer) = 0;

        int GetDrawOrder() const { return draw_order_; }

    protected:
        int draw_order_;
    };
}
