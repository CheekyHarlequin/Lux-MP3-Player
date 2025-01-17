#include "header/Lux-MP3-Player.h"
#include "header/buttons.h"

/*
#TODO
Update textures when resizing window, currently not working, even with given
functions
*/

void render_all_buttons();
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

// define buttons
Button play_button;
Button pause_button;
Button replay_off_button;
Button replay_on_button;
Button list_button;
Button last_button;
Button next_button;

void render_main() {
  update_rect_pos(&background_Rect);
  update_rect_pos(&main_UI_Rect);

  load_main_textures();
  SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);

  SDL_GetWindowSize(main_window, &window_width_new, &window_height_new);
  update_main_rects(window_width_new, window_height_new);
  SDL_RenderClear(main_renderer);

  render_main_textures();
  renderButton(&play_button, main_renderer);
  renderButton(&pause_button, main_renderer);
  renderButton(&last_button, main_renderer);
  renderButton(&next_button, main_renderer);
  renderButton(&replay_off_button, main_renderer);
  renderButton(&replay_on_button, main_renderer);
  renderButton(&list_button, main_renderer);
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

void initialize_buttons() {
  play_button = createButton(710, 825, 75, 100, main_renderer,
                             "main-window-textures/play.png", true);
  pause_button = createButton(710, 825, 75, 100, main_renderer,
                              "main-window-textures/pause.png", false);
  last_button = createButton(610, 825, 75, 100, main_renderer,
                             "main-window-textures/last-button.png", true);
  next_button = createButton(810, 825, 75, 100, main_renderer,
                             "main-window-textures/next-button.png", true);
  replay_off_button = createButton(1330, 825, 75, 100, main_renderer,
                                   "main-window-textures/replay-off.png", true);
  replay_on_button = createButton(1330, 825, 75, 100, main_renderer,
                                  "main-window-textures/replay-on.png", false);
  list_button = createButton(510, 825, 75, 100, main_renderer,
                             "main-window-textures/List.png", true);
}
