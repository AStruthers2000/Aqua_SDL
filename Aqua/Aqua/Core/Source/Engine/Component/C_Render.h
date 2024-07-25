#pragma once
#include <SDL_render.h>
#include "Component.h"
#include "GameStates/GameState.h"

namespace AquaEngine
{
    class C_Render : public Component
    {
    public:
        C_Render(Actor* owner, int draw_order)
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
