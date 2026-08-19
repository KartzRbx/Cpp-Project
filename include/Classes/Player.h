#include <string>

#pragma once

struct Player {
    private:
        // ------------------------------------
                // Class Values
                    std::string Name;
                    int Health;

        // ------------------------------------

    public:
        // ------------------------------------
            // Constructor
            Player(std::string name, const int Health): Name(name), Health(Health) {}
    

            // Functions Definitions
            std::string TakeDamage(int amout);

        // ------------------------------------
};