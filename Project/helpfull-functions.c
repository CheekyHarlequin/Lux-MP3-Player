#include "header/Lux-MP3-Player.h"

// All button-functions following:
Button buttons[NUM_OF_BUTTONS];
// to create buttons
Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer,
                    const char *image_path, bool shall_display) {
  Button button;
  button.rect.x = x;
  button.rect.y = y;
  button.rect.w = w;
  button.rect.h = h;
  button.to_display = shall_display;
  SDL_Surface *surface = IMG_Load(image_path);
  if (!surface) {
    printf("IMG_Load Error: %s\n", IMG_GetError());
    button.texture = NULL;
    return button;
  }

  button.texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  if (!button.texture) {
    printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
  }

  return button;
}

int get_pressed_button(int x, int y) {
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    SDL_Rect *rect = &buttons[i].rect;
    if (buttons[i].to_display && x >= rect->x && x < (rect->x + rect->w) &&
        y >= rect->y && y < (rect->y + rect->h)) {
      return i; // Return the index of the pressed button
    }
  }
  return -1; // Return -1 if no button was pressed
}

// Function to render a button

void updateButtonRect(Button *button, int windowWidth, int windowHeight) {
  button->rect.x = button->rect.x * windowWidth / 800;
  button->rect.y = button->rect.y * windowHeight / 600;
  button->rect.w = button->rect.w * windowWidth / 800;
  button->rect.h = button->rect.h * windowHeight / 600;
}

SDL_Texture *loadTexture(char *path, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load(path);
  if (!surface) {
    printf("Failed to load image: %s\n", IMG_GetError());
    return NULL;
  }
  SDL_Texture *texPtr = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texPtr;
}

void initialize_all() {
  initialize_SDL();
  initialize_buttons(main_renderer);
  load_main_textures();
  initialize_music("music");
}
// To kill the programm
void terminate() {
  // main textures
  free_music();
  SDL_DestroyTexture(background_Texture);
  SDL_DestroyTexture(main_UI_Texture);
  // main window
  SDL_DestroyRenderer(main_renderer);
  SDL_DestroyWindow(main_window);
  Mix_Quit();
  SDL_Quit();
  exit(0);
}
