#include "header/Lux-MP3-Player.h"

Mix_Music *bgm;

int initialize_music() {
  bgm = Mix_LoadMUS(
      "music/[TW] Top 10 Things To Do Before You Die (Uncensored).mp3");
  if (bgm == NULL) {
    printf("Musikdatei konnte nicht geladen werden! SDL_mixer Error: %s\n",
           Mix_GetError());
    return -1;
  }
}
