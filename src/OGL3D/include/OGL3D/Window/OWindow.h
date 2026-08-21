#pragma once

class OWindow {
public:
    OWindow(int width, int height, const char* title);
    ~OWindow();

    bool ShouldClose() const;
    void BeginFrame();
    void EndFrame();
    void Clear(unsigned char r, unsigned char g, unsigned char b);

    int GetWidth() const;
    int GetHeight() const;
    void SetWindowSize(bool Full);

private:
    bool initialized = false;
};
