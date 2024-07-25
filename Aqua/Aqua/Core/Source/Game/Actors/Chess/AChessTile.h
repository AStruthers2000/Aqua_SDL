#pragma once
#include <memory>

#include "Actor/Actor.h"
#include "Component/Rendering/CSquareRenderer.h"

class AChessTile : public AquaEngine::Actor
{
public:
    explicit AChessTile(AquaEngine::GameState* game_state, AquaColor tile_color)
        : Actor(game_state)
    {

        
        const auto c = std::make_shared<AquaEngine::CSquareRenderer>(
            this,
            10,
            tile_color,
            AquaEngine::Vector2(0, 0),
            AquaEngine::Vector2(25, 25));

        AddComponent(c);
    }

    ~AChessTile() override;
    void BeginPlay() override;
    void TickActor(float delta_time) override;
    
};
