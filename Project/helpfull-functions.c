#include "header/Lux-MP3-Player.h"

// Funktion zur Initialisierung eines Knopfes
Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer,
                    const char *image_path) {
  Button button;
  button.rect.x = x;
  button.rect.y = y;
  button.rect.w = w;
  button.rect.h = h;

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

// Funktion zum Rendern eines Knopfes
void renderButton(Button button, SDL_Renderer *renderer, int window_width,
                  int window_height) {

  SDL_RenderCopy(renderer, button.texture, NULL, &button.rect);
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

void updateButtonRect(Button *button, int windowWidth, int windowHeight) {
  button->rect.x = button->rect.x * windowWidth / 800;
  button->rect.y = button->rect.y * windowHeight / 600;
  button->rect.w = button->rect.w * windowWidth / 800;
  button->rect.h = button->rect.h * windowHeight / 600;
}
// for buttons

// To kill the programm
void terminate() {
  // main textureres
  SDL_DestroyTexture(background_Texture);
  // main window
  SDL_DestroyRenderer(main_renderer);
  SDL_DestroyWindow(main_window);

  SDL_Quit();
  exit(0);
}
