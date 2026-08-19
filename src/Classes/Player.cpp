#include <string>


#include "Classes/Player.h"

std::string Player::TakeDamage(int amount) {
    Health -= amount;

    return "Player has taken damage. Current Health: " + std::to_string(Health);
}

const int Player::GetHealth() {
	return Health;
}


