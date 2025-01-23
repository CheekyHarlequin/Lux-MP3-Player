#include "header/Lux-MP3-Player.h"
#include "header/buttons.h"

// Original screen size
const int ORIGINAL_WINDOW_WIDTH = 1920;
const int ORIGINAL_WINDOW_HEIGHT = 1080;

SDL_Rect original_button_rects[NUM_OF_BUTTONS] = {
    {710, 845, 75, 100}, {710, 845, 75, 100},  {610, 845, 75, 100},
    {810, 845, 75, 100}, {1330, 845, 75, 100}, {1330, 845, 75, 100},
    {510, 845, 75, 100}};

bool get_initial_display_state(int index);

void render_all_buttons();
const char *get_image_path(int index);
void update_button_rects(int window_width, int window_height);
// helpfull render main functions
void load_main_textures();
void render_main_textures();

void update_rect_size(SDL_Rect *rect, int window_width, int window_height);
void update_main_rects(int window_width, int window_height);
void update_rect_pos(SDL_Rect *rect);
void renderButtons(SDL_Renderer *main_renderer);

SDL_Texture *background_Texture = NULL;
SDL_Texture *main_UI_Texture = NULL;

SDL_Rect background_Rect;
SDL_Rect main_UI_Rect;
int window_width_new = 1920;
int window_height_new = 1080;

void render_main() {
  update_rect_pos(&background_Rect);
  update_rect_pos(&main_UI_Rect);

  SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);

  SDL_GetWindowSize(main_window, &window_width_new, &window_height_new);
  update_main_rects(window_width_new, window_height_new);
  update_button_rects(window_width_new,
                      window_height_new); // Knöpfe aktualisieren
  SDL_RenderClear(main_renderer);

  render_main_textures();
  renderButtons(main_renderer);
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

void initialize_buttons(SDL_Renderer *renderer) {
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    buttons[i] =
        createButton(original_button_rects[i].x, original_button_rects[i].y,
                     original_button_rects[i].w, original_button_rects[i].h,
                     renderer, get_image_path(i), get_initial_display_state(i));
  }
}

// Helper functions to get image path and display state
const char *get_image_path(int index) {
  switch (index) {
  case 0:
    return "main-window-textures/play.png";
  case 1:
    return "main-window-textures/pause.png";
  case 2:
    return "main-window-textures/last-button.png";
  case 3:
    return "main-window-textures/next-button.png";
  case 4:
    return "main-window-textures/replay-off.png";
  case 5:
    return "main-window-textures/replay-on.png";
  case 6:
    return "main-window-textures/List.png";
  default:
    return "";
  }
}

bool get_initial_display_state(int index) { return (index != 1 && index != 5); }

// to render buttons
void renderButtons(SDL_Renderer *main_renderer) {
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    if (buttons[i].to_display) {
      SDL_RenderCopy(main_renderer, buttons[i].texture, NULL, &buttons[i].rect);
    }
  }
}

void update_button_rects(int window_width, int window_height) {
  float width_ratio = (float)window_width / (float)ORIGINAL_WINDOW_WIDTH;
  float height_ratio = (float)window_height / (float)ORIGINAL_WINDOW_HEIGHT;

  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    buttons[i].rect.x = original_button_rects[i].x * width_ratio;
    buttons[i].rect.y = original_button_rects[i].y * height_ratio;
    buttons[i].rect.w = original_button_rects[i].w * width_ratio;
    buttons[i].rect.h = original_button_rects[i].h * height_ratio;
  }
}

void initialize_all_textures() {
  initialize_buttons(main_renderer);
  load_main_textures();
}
