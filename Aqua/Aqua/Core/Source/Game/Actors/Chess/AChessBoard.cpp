#include "AChessBoard.h"

void AChessBoard::BeginPlay()
{
}

void AChessBoard::TickActor(float delta_time)
{
    const float speed { 50.f };
    const AquaEngine::Vector2 delta_position = speed * delta_time;
    SetActorPosition(GetActorPosition() + delta_position);
}
