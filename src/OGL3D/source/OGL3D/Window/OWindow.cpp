#include "OGL3D/Window/OWindow.h"

#include "raylib.h"

OWindow::OWindow(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
   
    initialized = IsWindowReady();
}

OWindow::~OWindow() {
    if (initialized) {
        CloseWindow();
    }
}

void OWindow::SetWindowSize(bool Full){
    if (Full) {
        MaximizeWindow();
    }
}

bool OWindow::ShouldClose() const {
    return WindowShouldClose();
}

void OWindow::BeginFrame() {
    BeginDrawing();
}

void OWindow::EndFrame() {
    EndDrawing();
}

void OWindow::Clear(unsigned char r, unsigned char g, unsigned char b) {
    ClearBackground({ r, g, b, 255 });
}

int OWindow::GetWidth() const {
    return GetScreenWidth();
}

int OWindow::GetHeight() const {
    return GetScreenHeight();
}
