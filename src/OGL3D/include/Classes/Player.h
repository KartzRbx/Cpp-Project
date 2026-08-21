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
                    /*  POSITION */
                    float X;
                    float Y;
                    /*  SIZE */
                    float Width;
                    float Height;
                    /*  SPEED */
                    float Speed;

        // ------------------------------------

    public:

        // ------------------------------------
            // Constructor
            Player(std::string name, const int Health, float x, float y)
                : Name(name), Health(Health), X(x), Y(y), Width(40.0f), Height(40.0f), Speed(220.0f) {}
    

            // Functions Definitions
            std::string TakeDamage(int amout);
            int GetHealth() const;
            const std::string& GetName() const;
            float GetX() const;
            float GetY() const;
            float GetWidth() const;
            float GetHeight() const;

            void Update(float deltaTime);
            void Draw() const;

        // ------------------------------------
};
