#pragma once
#include <functional>
#include <memory>

#include "Actor/Actor.h"
#include "AquaColor.h"
#include "Component/Component.h"

namespace AquaEngine
{
    template <typename T>
    class CGridComponent : public Component
    {
    public:
        CGridComponent(Actor* owner, int update_order, int grid_x, int grid_y, std::function<std::shared_ptr<T>(GameState*, AquaColor color)> tile_factory)
            : Component(owner, update_order), grid_x_(grid_x), grid_y_(grid_y), tile_factory_(tile_factory)
        {
            grid_objects_.resize(grid_x * grid_y);
            constexpr AquaColor black {0, 0, 0, 255};
            constexpr AquaColor white {255, 255, 255, 255};
            int tile_count = 0;
            for(int y = 0; y < grid_y; y++)
            {
                for(int x = 0; x < grid_x; x++)
                {
                    const int index = y * grid_x + x;
                    AquaColor c = tile_count % 2 == 0 ? black : white;
                    grid_objects_[index] = tile_factory_(owner->GetActorWorld(), c);
                    
                    tile_count++;
                }
                tile_count--;
            }
        }

        void TickComponent(float delta_time) override;

    protected:
        int grid_x_, grid_y_;
        std::vector<std::shared_ptr<T>> grid_objects_;
        std::function<std::shared_ptr<T>(GameState*, AquaColor)> tile_factory_;
    };

    template <typename T>
    void CGridComponent<T>::TickComponent(float delta_time)
    {
        for(int y = 0; y < grid_y_; y++)
        {
            for(int x = 0; x < grid_x_; x++)
            {
                const int index = y * grid_x_ + x;
                std::dynamic_pointer_cast<Actor>(grid_objects_[index])->SetActorPosition(
                        Vector2(owner_->GetActorPosition().x + 25 * x,
                            owner_->GetActorPosition().y + 25 * y)
                        );
            }
        }
    }
}
