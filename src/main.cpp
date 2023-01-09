#include "game.hpp"

int main(int argc, char* argv[]){
    
    fr0sty::Game::getInstance()->sys_print("WORKING PROPERLY!", true);
    fr0sty::Game::getInstance()->run();
    

    return 0; 
}
