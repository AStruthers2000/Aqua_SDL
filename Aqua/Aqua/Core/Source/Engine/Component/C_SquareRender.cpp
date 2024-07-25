#include "C_SquareRender.h"

void AquaEngine::C_SquareRender::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, color_.red, color_.blue, color_.green, color_.alpha);

    const SDL_Rect rect = {static_cast<int>(owner_->GetActorPosition().x), static_cast<int>(owner_->GetActorPosition().y), size_.x, size_.y};
    SDL_RenderFillRect(renderer, &rect);
}
