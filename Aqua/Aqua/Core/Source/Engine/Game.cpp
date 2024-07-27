#include "Game.h"

#include <iostream>
#include <SDL.h>

//#include "GameStates/GameState.h"
//#include "GameStates/GameSubState.h"
#include "GameStates/GameState.h"
#include "../Game/GameStates/GameState_MainMenu.h"

namespace AquaEngine
{
    Game::Game(const float fps) : window(nullptr), renderer(nullptr), is_running(false), target_fps(fps)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cerr << "[Game::Game]:\tSDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        }

        window = SDL_CreateWindow("Aqua",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screen_dimensions.x,
            screen_dimensions.y,
            0);

        if(window == nullptr)
        {
            std::cerr << "[Game::Game]:\tWindow could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }

        renderer = SDL_CreateRenderer(window,
            -1,
            SDL_RENDERER_ACCELERATED);

        if(renderer == nullptr)
        {
            std::cerr << "[Game::Game]:\tRenderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }

        PushGameState(std::make_unique<GameState_MainMenu>(this, "Main Menu"));

        is_running = true;
        std::cout << "[Game::Game]:\tGame initialized successfully" << std::endl;
    }

    Game::~Game()
    {
        std::cout << "[Game::~Game]:\tQuitting game and destroying game states" << std::endl;
        while(!game_states.empty())
        {
            game_states.pop();
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Game::Run()
    {
        const float frame_delay { 1000.0f / target_fps };
        std::cout << "[Game::Run]:\tRunning game with a target FPS of " << target_fps << " and a frame delay of " << frame_delay << " ms" << std::endl;

        //float frame_time { 0.f };
        Uint64 tick_count_from_start { 0 };

        while(IsRunning())
        {
            while(!SDL_TICKS_PASSED(SDL_GetTicks64(), static_cast<Uint64>(static_cast<float>(tick_count_from_start) + frame_delay)))
                ;

            float delta_time = static_cast<float>(SDL_GetTicks64() - tick_count_from_start) / 1000.f;
            //if(delta_time > 0.05f) delta_time = 0.05f;
            if(delta_time > 1.f)
            {
                std::cerr << "[Game::Run]:\tLess than 1 fps detected..." << std::endl;
                delta_time = 1.f;
            }
            tick_count_from_start = SDL_GetTicks64();

            HandleEvents();
            Update(delta_time);
            Render();


            //std::cout << "[Game::Run]:\tdelta time: " << delta_time << std::endl;
            //std::cout << "[Game::Run]:\tframe ticks: " << tick_count_from_start << std::endl;
        }
    }

    void Game::PushGameState(std::unique_ptr<GameState> state)
    {
        game_states.push(std::move(state));
        game_states.top()->BeginPlay();
    }

    void Game::PopGameState()
    {
        if(!game_states.empty())
        {
            game_states.pop();
        }
    }

    void Game::ChangeState(std::unique_ptr<GameState> state)
    {
        PopGameState();
        PushGameState(std::move(state));
    }

    void Game::HandleEvents()
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                is_running = false;
            }
        
            if(!game_states.empty())
            {
                game_states.top()->HandleInput(event);
            }
        }
    }

    void Game::Update(float delta_time)
    {
        if(!game_states.empty())
        {
            game_states.top()->Tick(delta_time);
        }
    }

    void Game::Render()
    {
        if(!game_states.empty())
        {
            game_states.top()->Render(renderer);
        }
    }
}