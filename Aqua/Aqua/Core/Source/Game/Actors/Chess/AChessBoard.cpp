#include "AChessBoard.h"

#include "EngineParameters.h"
#include "Component/Collision/CSquareCollider.h"

void AChessBoard::BeginPlay()
{
    auto chess_tile_factory = [](AquaEngine::GameState* state, AquaColor color) -> std::shared_ptr<AChessTile>
    {
        return std::make_shared<AChessTile>(state, color);
    };

    AddComponent(std::make_shared<AquaEngine::CSquareCollider>(this, 1, AquaEngine::Vector2{1, 1}));
    board = std::make_shared<AquaEngine::CGridComponent<AChessTile>>(
        this,
        1,
        10,
        10,
        chess_tile_factory);
    AddComponent(board);
    AddComponent(std::make_shared<AquaEngine::CSquareRenderer>(this, 1, AquaColor{255, 0, 255, 255}, AquaEngine::Vector2{0.f, 0.f}));

    SetActorPosition(AquaEngine::Vector2(AquaEngine::screen_dimensions.x / 2,AquaEngine::screen_dimensions.y / 2));
    board->UpdateGridPosition();
    
    if(const auto collider = TryGetComponent<AquaEngine::CSquareCollider>())
    {
        std::cout << "[AChessBoard::BeginPlay]:\tMy bounds are (" << collider->GetBounds().GetSize().x << ", " << collider->GetBounds().GetSize().y << ")" << std::endl;
        std::cout << "[AChessBoard::BeginPlay]:\tMy top left corner is at (" << collider->GetBounds().GetMin().x + GetActorPosition().x << ", " << collider->GetBounds().GetMin().y + GetActorPosition().y <<
            "), and my bottom right corner is at (" << collider->GetBounds().GetMax().x  + GetActorPosition().x << ", " << collider->GetBounds().GetMax().y + GetActorPosition().y << ")" <<std::endl;

        if(const auto renderer = TryGetComponent<AquaEngine::CSquareRenderer>())
        {
            std::cout << "[AChessBoard::BeginPlay]:\tUpdating renderer size" << std::endl;
            renderer->GetBoundsRef()->SetSize(collider->GetBounds().GetSize());
        }
    }
}

void AChessBoard::TickActor(float delta_time)
{
    const float speed { 50.f };
    const AquaEngine::Vector2 delta_position = speed * delta_time;
    //SetActorPosition(GetActorPosition() + delta_position);
    //board->UpdateGridPosition();

    //const auto tile = board->GetGridObject(0, 7);
    //if(!tile) return;
    //std::cout << "(" << tile->GetActorPosition().x << ", " << tile->GetActorPosition().y << ")" << std::endl;
}
