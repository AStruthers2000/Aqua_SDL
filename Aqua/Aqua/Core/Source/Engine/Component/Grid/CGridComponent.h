#pragma once
#include <functional>
#include <memory>
#include <iostream>

#include "Actor/Actor.h"
#include "AquaColor.h"
#include "Component/Component.h"
#include "Component/Collision/CCollider.h"
#include "Component/Rendering/CSquareRenderer.h"

namespace AquaEngine
{
    template <typename T>
    class CGridComponent : public Component
    {
    public:
        CGridComponent(Actor* owner, int update_order, int grid_rows, int grid_cols, std::function<std::shared_ptr<T>(GameState*, AquaColor color)> tile_factory)
            : Component(owner, update_order), grid_rows_(grid_rows), grid_cols_(grid_cols), tile_factory_(tile_factory)
        {
            if(grid_rows_ < 1) grid_rows_ = 1;
            if(grid_cols_ < 1) grid_cols_ = 1;
            
            grid_objects_.resize(grid_rows_ * grid_cols_);
            constexpr AquaColor black {0, 0, 0, 255};
            constexpr AquaColor white {255, 255, 255, 255};

            int tile_count = 0;
            for(int row = 0; row < grid_rows_; row++)
            {
                for(int col = 0; col < grid_cols_; col++)
                {
                    const int index = row * grid_cols_ + col;
                    
                    AquaColor c = tile_count % 2 == 0 ? black : white;
                    grid_objects_[index] = tile_factory_(owner->GetActorWorld(), c);

                    UpdateTilePosition(index, row, col);
                    
                    //std::cout << "[CGridComponent::CGridComponent]:\tRow: " << row << ", col: " << col << " has index: " << index << " and is at position: ("
                    //<< std::dynamic_pointer_cast<Actor>(grid_objects_[index])->GetActorPosition().x << ", " << std::dynamic_pointer_cast<Actor>(grid_objects_[index])->GetActorPosition().y << ")" << std::endl;
                    tile_count++;
                }
                tile_count--;
            }
            
            if(const auto actor_collider = owner_->TryGetComponent<CCollider>())
            {
                std::cout << "[CGridComponent::CGridComponent]:\tFound collider component on owner" << std::endl;
                const auto tile_bounds = GetTileBounds(0);
                actor_collider->GetBoundsRef()->SetSize({tile_bounds.GetSize().x * grid_cols_, tile_bounds.GetSize().y * grid_rows_});
            }
        }

        void TickComponent(float delta_time) override;
        std::shared_ptr<T> GetGridObject(const int row, const int col)
        {
            if(row < 0 || row >= grid_rows_)
            {
                std::cerr << "[CGridComponent::GetGridObject]:\tAttempted to select tile from nonexistant row" << std::endl;
                return nullptr;
            }
            if(col < 0 || col >= grid_cols_)
            {
                std::cerr << "[CGridComponent::GetGridObject]:\tAttempted to select tile from nonexistant column" << std::endl;
                return nullptr;
            }
            return grid_objects_[row * grid_cols_ + col];
        }

        void UpdateGridPosition() const
        {
            for(int row = 0; row < grid_rows_; row++)
            {
                for(int col = 0; col < grid_cols_; col++)
                {
                    const int index = row * grid_cols_ + col;
                    UpdateTilePosition(index, row, col);
                }
            }
        }

    protected:
        int grid_rows_, grid_cols_;
        std::vector<std::shared_ptr<T>> grid_objects_;
        std::function<std::shared_ptr<T>(GameState*, AquaColor)> tile_factory_;
        std::shared_ptr<Actor> GetTileActor(int index) const { return std::dynamic_pointer_cast<Actor>(grid_objects_[index]); }

        Bounds GetTileBounds(const int index) const
        {
            if(const auto tile_renderer = GetTileActor(index)->TryGetComponent<CSquareRenderer>())
            {
                const auto tile_bounds = tile_renderer->GetBounds();
                //std::cout << "[CGridComponent::CGridComponent]:\tSuccessfully found collider component on tile actor" << std::endl;
                return tile_bounds;
            }
            std::cerr << "[CGridComponent::CGridComponent]:\tCould not find renderer component on tile actor" << std::endl;
            return nullptr;
        }

    private:
        void UpdateTilePosition(int index, int row, int col) const
        {
            const auto owner_position = owner_->GetActorPosition();
            const auto owner_collider = owner_->TryGetComponent<CCollider>();
            if(!owner_collider)
            {
                return;
            }
            const auto owner_bounds = owner_collider->GetBounds();
            const auto tile_actor = GetTileActor(index);
            const auto tile_actor_bounds = GetTileBounds(index); 
            tile_actor->SetActorPosition(
                Vector2(
                    (owner_position.x - owner_bounds.GetHalfSize().x) + (tile_actor_bounds.GetSize().x * col) + tile_actor_bounds.GetHalfSize().x,
                    (owner_position.y - owner_bounds.GetHalfSize().y) + (tile_actor_bounds.GetSize().y * row) + tile_actor_bounds.GetHalfSize().y));
        }
    };

    template <typename T>
    void CGridComponent<T>::TickComponent(float delta_time)
    {
        
        
        
    }
}
