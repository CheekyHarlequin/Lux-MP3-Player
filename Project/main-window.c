#include "header/Lux-MP3-Player.h"
// global functions for this file alone

int main_window_io() {
  initialize_music();
  if (Mix_PlayMusic(bgm, -1) == -1) {
    printf("Musik konnte nicht abgespielt werden! SDL_mixer Error: %s\n",
           Mix_GetError());
  }

  initialize_buttons(main_renderer);
  load_main_textures();
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
        printf("Mouse button pressed at (%d, %d)\n", x, y);
        printf("Pressed button index: %d\n", pressed_button);
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
