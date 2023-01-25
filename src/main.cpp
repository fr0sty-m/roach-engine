#include "game.hpp"
using namespace fr0sty;

int main(int argc, char* argv[]){
    
    Game::getInstance()->sys_print("STARTING!", true);
    Game::getInstance()->init();
              
    float dt;

    while (Game::getInstance()->running()) {
        Game::getInstance()->events();
        Game::getInstance()->update(dt);

        dt = static_cast<float>(Game::getInstance()->getClock().getTicks()) / 1000.f; 
        Game::getInstance()->getClock().start();
       
        Game::getInstance()->preRender();
        Game::getInstance()->render();
        Game::getInstance()->postRender();
    }

    Game::getInstance()->quit();
    Game::getInstance()->sys_print("STOPPING!", true);

    return 0; 
}
