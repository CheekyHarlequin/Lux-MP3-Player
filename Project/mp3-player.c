#include "header/Lux-MP3-Player.h"
// main-window
SDL_Renderer *main_renderer;
SDL_Window *main_window;

// pop-up-window
SDL_Renderer *popup_renderer;
SDL_Window *popup_window;

// font
TTF_Font *defaultFont;

// Event-manager
SDL_Event main_event;

// Other global variables
bool is_main_closed = false;

bool is_popup_opened = false;
bool is_popup_closed = false;

int quit = 0;
// Target-FPS
const int TARGET_FPS = 30;
const int FRAME_DELAY = 1000 / TARGET_FPS;

// functions in and for this file
int initialize_all();

int main(int argc, char *argv[]) {
  // Initialisieren von SDL
  initialize_all();
  main_window_io();

  /* Shuts down all SDL subsystems */
  terminate();

  return 0;
}

int initialize_all() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer konnte nicht initialisiert werden! SDL_mixer Error: %s\n",
           Mix_GetError());
    return -1;
  }

  // Erstellen eines SDL-Fensters
  main_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, 1920, 1080,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED |
                                     SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
  if (main_window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // Erstellen eines SDL-Renderers
  main_renderer = SDL_CreateRenderer(
      main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (main_renderer == NULL) {
    SDL_DestroyWindow(main_window);
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  TTF_Init();

  if ((defaultFont = TTF_OpenFont("fonts/funky.ttf", 32)) == NULL) {
    printf("Font not found");
    terminate();
  }
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}
