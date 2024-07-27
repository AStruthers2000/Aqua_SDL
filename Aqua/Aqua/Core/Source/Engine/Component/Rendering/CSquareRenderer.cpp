#include "CSquareRenderer.h"

namespace AquaEngine
{
    void CSquareRenderer::Draw(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, color_.red, color_.blue, color_.green, color_.alpha);

        const SDL_Rect rect = {
            static_cast<int>(owner_->GetActorPosition().x - GetBounds().GetHalfSize().x),
            static_cast<int>(owner_->GetActorPosition().y - GetBounds().GetHalfSize().y),
            static_cast<int>(GetBounds().GetSize().x),
            static_cast<int>(GetBounds().GetSize().y)
        };
        
        SDL_RenderFillRect(renderer, &rect);
    }
}