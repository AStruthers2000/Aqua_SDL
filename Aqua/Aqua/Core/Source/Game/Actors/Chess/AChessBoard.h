#pragma once
#include "AChessTile.h"
#include "Actor/Actor.h"
#include "Component/Grid/CGridComponent.h"

class AChessBoard : public AquaEngine::Actor
{
public:
    explicit AChessBoard(AquaEngine::GameState* game_state)
        : Actor(game_state)
    {
        
        auto chess_tile_factory = [](AquaEngine::GameState* state, AquaColor color) -> std::shared_ptr<AChessTile>
        {
            return std::make_shared<AChessTile>(state, color);
        };

        
        AddComponent(std::make_shared<AquaEngine::CGridComponent<AChessTile>>(
            this,
            1,
            8,
            8,
            chess_tile_factory));

        SetActorPosition(AquaEngine::Vector2(50,50));
    }

    void BeginPlay() override;
    void TickActor(float delta_time) override;
};
