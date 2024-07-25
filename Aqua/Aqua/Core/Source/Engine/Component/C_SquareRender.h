#pragma once
#include "AquaColor.h"
#include "C_Render.h"

namespace AquaEngine
{
    class C_SquareRender : public C_Render
    {
    public:
        C_SquareRender(Actor* owner, int draw_order, const AquaColor color, const Vector2<int>& position, const Vector2<int>& size)
            : C_Render(owner, draw_order), color_(color), position_(position), size_(size)
        {
        }

        void Draw(SDL_Renderer* renderer) override;

    private:
        AquaColor color_;
        Vector2<int> position_;
        Vector2<int> size_;
    };
}