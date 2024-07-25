#pragma once
#include "AquaColor.h"
#include "CRenderer.h"

namespace AquaEngine
{
    class CSquareRenderer : public CRenderer
    {
    public:
        CSquareRenderer(Actor* owner, int draw_order, const AquaColor color, const Vector2<int>& position, const Vector2<int>& size)
            : CRenderer(owner, draw_order), color_(color), position_(position), size_(size)
        {
        }

        void Draw(SDL_Renderer* renderer) override;
        ~CSquareRenderer() override;

    private:
        AquaColor color_;
        Vector2<int> position_;
        Vector2<int> size_;
    };
}