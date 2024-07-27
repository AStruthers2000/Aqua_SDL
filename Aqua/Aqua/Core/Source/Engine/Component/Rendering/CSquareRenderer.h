#pragma once
#include "AquaColor.h"
#include "CRenderer.h"

namespace AquaEngine
{
    class CSquareRenderer : public CRenderer
    {
    public:
        CSquareRenderer(Actor* owner, int draw_order, const AquaColor color, const Vector2<float>& size)
            : CRenderer(owner, draw_order, size), color_(color)
        {
        }

        void Draw(SDL_Renderer* renderer) override;

    private:
        AquaColor color_;
    };
}