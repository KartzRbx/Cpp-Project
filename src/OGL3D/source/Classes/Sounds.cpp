#include "Classes/Sounds.h"

// Definitions
const char* SoundSetup::LobbySoundPath = "assets/sounds/Lobby.mp3";

Sound SoundSetup::SetupMusicMenu() {
    InitAudioDevice();
    return LoadSound(LobbySoundPath);
}
