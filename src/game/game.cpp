#include "game.hpp"
#include "SDL/SDL_image.h"
#include "SDL/SDL_render.h"
#include "settings.hpp"

// INITIALIZING GAME INSTANCE
fr0sty::Game* fr0sty::Game::_instance = nullptr;

namespace fr0sty {
    bool Game::init() {

        // INITIALIZING SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) != 0) {
            Game::sys_print("FAILED TO INITIALIZE SDL", true);
            return _running = false;
        }

        // CREATING WINDOW
        _window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if (_window == nullptr) {
            Game::sys_print("FAILED TO CREATE WINDOW!", true);
            return _running = false;
        }

        // CREATING RENDERER
        _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == nullptr) {
            Game::sys_print("FAILED TO CREATE RENDERER!", true);
            return _running = false;
        }
        
        img = IMG_LoadTexture(_renderer, HELLO_IMG_PATH);


        return _running = true;
    }

    bool Game::quit() {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);

        IMG_Quit();
        SDL_Quit();

        return _running = false;
    } 

    void Game::update(float dt) {

    }

    void Game::preRender() {
        SDL_SetRenderDrawColor(_renderer, GAME_BG_COLOR);
        SDL_RenderClear(_renderer);
    }

    void Game::render() {
        // DRAW
        SDL_RenderCopy(_renderer, img, NULL, NULL);
        
    }

    void Game::postRender() {
        SDL_RenderPresent(_renderer);
    }

    void Game::events() {
        SDL_PollEvent(&_event);

        switch (_event.type) {
        case SDL_QUIT:
            _running = false;
            quit();
            break;
        case SDL_KEYDOWN:
            switch (_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _running = false;
                    quit();
                    break;
            }
        }
    }

} // 	 fr0sty
