#include <string>

#pragma once

struct Player {
    private:
        // ------------------------------------
                // Propeties
                    
                    /*  NAME */
                    std::string Name;
                    /*  HEALTH */
                    int Health;

        // ------------------------------------

    public:

        // ------------------------------------
            // Constructor
            Player(std::string name, const int Health): Name(name), Health(Health) {}
    

            // Functions Definitions
            std::string TakeDamage(int amout);
            const int GetHealth();

        // ------------------------------------
};