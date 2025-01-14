#include "Lux-MP3-Player.h"

void load_main_textures(); // Deklaration der Funktion

SDL_Texture *background_Texture =
    NULL; // Korrekte Deklaration und Initialisierung

void render_main() {
  load_main_textures(); // Aufruf der Funktion

  SDL_Rect background_Rect = {100, 100, 200, 150};

  SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
  SDL_RenderClear(main_renderer);

  SDL_RenderCopy(main_renderer, background_Texture, NULL, &background_Rect);

  SDL_RenderPresent(main_renderer);
}

void load_main_textures() {
  background_Texture =
      loadTexture("main-window-textures/background.png", main_renderer);
}
