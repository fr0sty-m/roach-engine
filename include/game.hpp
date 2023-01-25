#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "settings.hpp"
#include "clock.hpp"

namespace fr0sty {

    /// @brief An enum class for handling game states
    enum class STATE { PLAY, SPLASH, MENU };

    class Game {
        private:
            Game() = default;

            static Game* _instance;

            bool _running;       

            SDL_Window* _window;
            SDL_Renderer* _renderer;
            SDL_Surface* _surface;
            SDL_Texture *img;

            Clock _clock;
            float _dt;
            STATE _state;

            SDL_Event _event;


        public:
            /// @brief A method for Engine output
            /// @param msg The string to be printed
            /// @param endl end line = true 
            void sys_print(const char* msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}
            /// @brief A method for Engine output
            /// @param msg The integer to be printed
            /// @param endl end line = true 
            void sys_print(int msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}
            /// @brief A method for Engine output
            /// @param msg Your message
            /// @param endl end line = true 
            void sys_print(float msg, bool endl) {if (endl) {std::cout << "ROACH: " << msg << std::endl;} else {std::cout << msg;}}

            /// @brief A method for getting Game class instance
            /// @return Game class instance
            static Game* getInstance() { return _instance = (_instance != nullptr) ? _instance : new Game(); }

            /// @brief A method for getting if game is running
            /// @return Boolean variable
            bool running() { return _running; }

            /// @brief A method for initializing everything
            bool init();
            /// @brief A method for initializing variables
            bool initVars();
            /// @brief A method for initializing window
            bool initWindow();

            /// @brief A method for cleaning and stopping 
            bool quit();

            /// @brief A method for updating events every frame 
            void update(float dt);

            /// @brief A method for clearing scene
            void preRender();
            /// @brief A method for rendering textures every frame
            void render();
            /// @brief A method for showing render
            void postRender();  
            
            /// @brief A method for polling events
            void events();

            /// @brief A method for getting delta time variable 
            float getDT() { return _dt; }

            /// @brief A getter method for clock
            Clock &getClockInstance() { return _clock; }
        
        };	// fr0sty
}	// fr0sty
#endif // GAME_HPP
