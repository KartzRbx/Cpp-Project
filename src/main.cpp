#include <iostream>
#include <string>

/*
    GAME INCLUDES
*/
#include "Player.h"

// 1. Implementação do método do Player (fora de qualquer outra função)
void Player::TakeDamage(int amount) {
    Health -= amount;
}

// 2. Função de inicialização
void InitializePlayer() {
    std::cout << "Inicializando jogador...\n";
};

// 3. Ponto de entrada do programa
int main() {
    InitializePlayer();

    Player p1;
    p1.Health = 100;
    p1.TakeDamage(20);

    std::cout << "Vida restante: " << p1.Health << "\n";

    return 0;
}