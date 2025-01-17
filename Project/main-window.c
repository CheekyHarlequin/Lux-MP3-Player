#include "header/Lux-MP3-Player.h"
// global functions for this file alone

int main_window_io() {
  // Input-Bar ranges (435<--x-->1540) and (790<--y-->960)
  // 100 button should be in the middle, at 825 for h = 100
  Button play_button = createButton(600, 825, 150, 100, main_renderer,
                                    "main-window-textures/play.png", true);
  /*
    Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer,
    const char *image_path, bool shall_display); Button createButton(int x, int
    y, int w, int h, SDL_Renderer *renderer, const char *image_path, bool
    shall_display); Button createButton(int x, int y, int w, int h, SDL_Renderer
    *renderer, const char *image_path, bool shall_display); Button
    createButton(int x, int y, int w, int h, SDL_Renderer *renderer, const char
    *image_path, bool shall_display); Button createButton(int x, int y, int w,
    int h, SDL_Renderer *renderer, const char *image_path, bool shall_display);
    */
  render_main();
  renderButton(&play_button, main_renderer);
  SDL_RenderPresent(main_renderer);

  SDL_Delay(10000);

  return 1;
}
