#include <iostream>
#include <string>


/*
    GAME REQUIRES
*/

#include "Classes/Player.h"

Player CreateEntity(std::string Name, const int Health) {
   Player NewPlayer(Name, Health);
    return NewPlayer;
}

int main() {

    Player User = CreateEntity("User123", 100); 
    std::string PrintValue = User.TakeDamage(100);
    std::cout << PrintValue << std::endl;

    return 0;
}