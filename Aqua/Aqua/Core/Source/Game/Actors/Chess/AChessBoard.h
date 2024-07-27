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
        
        
    }

    void BeginPlay() override;
    void TickActor(float delta_time) override;

    std::shared_ptr<AquaEngine::CGridComponent<AChessTile>> board;
};
