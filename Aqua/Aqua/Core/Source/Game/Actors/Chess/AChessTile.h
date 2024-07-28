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

        //const AquaEngine::Bounds bounds = {50, 50}; 
        //SetActorBounds(bounds);


        
        const auto size = AquaEngine::Vector2{50.f};

        
        const auto c = std::make_shared<AquaEngine::CSquareRenderer>(
            this,
            1000,
            tile_color,
            size);

        AddComponent(c);
        
    }

    ~AChessTile() override;
    void BeginPlay() override;
    void TickActor(float delta_time) override;
    
};
