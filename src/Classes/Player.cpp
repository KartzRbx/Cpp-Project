#include <cmath>
#include <string>

#include "Classes/Player.h"
#include "raylib.h"

std::string Player::TakeDamage(int amount) {
    Health -= amount;

    return "Player has taken damage. Current Health: " + std::to_string(Health);
}

int Player::GetHealth() const {
	return Health;
}

const std::string& Player::GetName() const {
    return Name;
}

float Player::GetX() const {
    return X;
}

float Player::GetY() const {
    return Y;
}

float Player::GetWidth() const {
    return Width;
}

float Player::GetHeight() const {
    return Height;
}

void Player::Update(float deltaTime) {
    float moveX = 0.0f;
    float moveY = 0.0f;

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  moveX -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) moveX += 1.0f;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    moveY -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  moveY += 1.0f;

    if (moveX != 0.0f || moveY != 0.0f) {
        float length = sqrtf(moveX * moveX + moveY * moveY);
        moveX /= length;
        moveY /= length;
    }

    X += moveX * Speed * deltaTime;
    Y += moveY * Speed * deltaTime;

    if (X < 0.0f) X = 0.0f;
    if (Y < 0.0f) Y = 0.0f;
    if (X + Width > GetScreenWidth()) X = GetScreenWidth() - Width;
    if (Y + Height > GetScreenHeight()) Y = GetScreenHeight() - Height;
}

void Player::Draw() const {
    DrawRectangle(static_cast<int>(X), static_cast<int>(Y),
                  static_cast<int>(Width), static_cast<int>(Height),
                  Color{ 80, 180, 255, 255 });

    DrawRectangleLines(static_cast<int>(X), static_cast<int>(Y),
                       static_cast<int>(Width), static_cast<int>(Height),
                       RAYWHITE);
}
