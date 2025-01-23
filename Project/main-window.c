#include "header/Lux-MP3-Player.h"
// global functions for this file alone

int main_window_io() {
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&main_event)) {
      switch (main_event.type) {
      case SDL_QUIT:
        terminate();
        break;
      case SDL_MOUSEBUTTONDOWN:
        int x, y;
        SDL_GetMouseState(&x, &y);
        int pressed_button = get_pressed_button(x, y);
        handle_button_pressed(pressed_button);
      default:
        render_main();
        SDL_RenderPresent(main_renderer);
        break;
      }
    }
  }

  return 1;
}
