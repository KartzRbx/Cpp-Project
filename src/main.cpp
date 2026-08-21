#include <iostream>
#include <string>

/*
    GAME REQUIRES
*/

#include "Classes/Player.h"
#include "Classes/Sounds.h"
#include "OGL3D/Window/OWindow.h"
#include "raylib.h"



/*
    SUPPORT FUNC
*/
Player CreateEntity(std::string Name, const int Health, float x = 0.0f, float y = 0.0f) {
   Player NewPlayer(Name, Health, x, y);
    return NewPlayer;
}


void setupGame(Sound lobbyMusic) {
	if (!IsSoundPlaying(lobbyMusic)) {
		PlaySound(lobbyMusic);
	}
}

int main() {
	int CurrentMonitor;
	int MonitorWidth;
	int MonitorHeight;
	bool fullSize = true;
	float dt;

	// InitWindow precisa existir ANTES de GetMonitorWidth/Height
	OWindow window(1280, 720, "Game de Teste");

	Image Icon = LoadImage("assets/images/eggsad.png");
	SetWindowIcon(Icon);
	UnloadImage(Icon);

	CurrentMonitor = GetCurrentMonitor();
	MonitorWidth = GetMonitorWidth(CurrentMonitor);
	MonitorHeight = GetMonitorHeight(CurrentMonitor);

	SetWindowSize(MonitorWidth, MonitorHeight);
	SetTargetFPS(60);

	window.SetWindowSize(fullSize);

	Sound lobbyMusic = SoundSetup::SetupMusicMenu();
	
	// Setup Entity
	Player User =  CreateEntity("Jogador", 100, 5, 1);

	while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
		setupGame(lobbyMusic);


        //----------------------------------------------------------------------------------
		dt = GetFrameTime();
		User.Update(dt);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

		ClearBackground(Color{ 25, 25, 35, 255 });

		User.Draw();

		DrawText("WASD / Setas para mover", 20, 20, 20, LIGHTGRAY);
		DrawFPS(20, 50);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

	UnloadSound(lobbyMusic);
	CloseAudioDevice();

	// CloseWindow fica no destrutor do OWindow
	return 0;
}