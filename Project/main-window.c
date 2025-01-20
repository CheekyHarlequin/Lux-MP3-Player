#include "header/Lux-MP3-Player.h"
// global functions for this file alone

int main_window_io() {
  initialize_buttons(main_renderer);

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
        switch (pressed_button) {
        case 0:
          printf("Button 1 (Play) pressed\n"); // Aktion für Play-Button
          buttons[0].to_display = false;       // Play-Button unsichtbar machen
          buttons[1].to_display = true;        // Pause-Button sichtbar machen
          break;
        case 1:
          printf("Button 2 (Pause) pressed\n"); // Aktion für Pause-Button
          buttons[1].to_display = false; // Pause-Button unsichtbar machen
          buttons[0].to_display = true;  // Play-Button sichtbar machen
          break;
        default:
          printf("No button pressed\n");
          break;
          render_main();
          SDL_RenderPresent(main_renderer);
          break;
        }
      default:
        render_main();
        SDL_RenderPresent(main_renderer);
        break;
      }
    }
  }

  return 1;
}
