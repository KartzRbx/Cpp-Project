#include <iostream>
#include <string>

/*
    GAME REQUIRES
*/

#include "Classes/Player.h"

/*
    SUPPORT FUNC
*/
Player CreateEntity(std::string Name, const int Health) {
   Player NewPlayer(Name, Health);
    return NewPlayer;
}

int main() {
    int TargetDamage;

    Player User = CreateEntity("User123", 100);

	int* DamagePoint = &TargetDamage;

	std::cout << "Enter the amount of damage to take: ";
    std::cin >> TargetDamage;

        
	if (!TargetDamage && TargetDamage < 0) {
		std::cout << "Damage amount cannot be negative." << std::endl;
	}
	else {
		std::string PrintValue = User.TakeDamage(TargetDamage);
		std::cout << PrintValue << std::endl;
	}

	std::cout << "Current Health: " << User.GetHealth() << std::endl;
    return 0;
}