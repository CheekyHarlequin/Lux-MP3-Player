#include "header/Lux-MP3-Player.h"

// helpfull render main functions
void load_main_textures();
void render_main_textures();

void update_rect_size(SDL_Rect *rect, int window_width, int window_height);
void update_main_rects(int window_width, int window_height);
void update_rect_pos(SDL_Rect *rect);

SDL_Texture *background_Texture = NULL;
SDL_Texture *main_UI_Texture = NULL;

SDL_Rect background_Rect;
SDL_Rect main_UI_Rect;
int window_width_new = 1920;
int window_height_new = 1080;
void render_main() {
  update_rect_pos(&background_Rect);
  update_rect_pos(&main_UI_Rect);

  load_main_textures();
  SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
  SDL_RenderClear(main_renderer);
  while (true) {
    SDL_GetWindowSize(main_window, &window_width_new, &window_height_new);
    update_main_rects(window_width_new, window_height_new);
    render_main_textures();

    SDL_RenderPresent(main_renderer);
  }
}

void load_main_textures() {
  background_Texture =
      loadTexture("main-window-textures/background.png", main_renderer);
  main_UI_Texture =
      loadTexture("main-window-textures/UI-MW.png", main_renderer);
}

void render_main_textures() {
  SDL_RenderCopy(main_renderer, background_Texture, NULL, &background_Rect);
  SDL_RenderCopy(main_renderer, main_UI_Texture, NULL, &main_UI_Rect);
}

void update_main_rects(int window_width, int window_height) {
  update_rect_size(&background_Rect, window_width, window_height);
  update_rect_size(&main_UI_Rect, window_width, window_height);
}

void update_rect_size(SDL_Rect *rect, int window_width, int window_height) {
  rect->w = window_width;
  rect->h = window_height;
}

void update_rect_pos(SDL_Rect *rect) {
  rect->y = 0;
  rect->x = 0;
}
