#include "header/Lux-MP3-Player.h"
// global functions for this file alone

int main_window_io() {
  initialize_buttons();

  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&main_event)) {
      switch (main_event.type) {
      case SDL_QUIT:
        terminate();
        break;

      default:
        render_main();
        SDL_RenderPresent(main_renderer);
        break;
      }
    }
  }

  return 1;
}
