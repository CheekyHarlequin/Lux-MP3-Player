#include "Lux-MP3-Player.h"

/* void drawText(SDL_Renderer *renderer, const int x, const int y,
              const char *text, TTF_Font **font, const SDL_Color *textColor) {
  const SDL_Color defaultColor = {0, 0, 0};

  // Draw with the according color
  SDL_Surface *surface =
      TTF_RenderText_Solid((font == NULL) ? defaultFont : *font, text,
                           (textColor == NULL) ? defaultColor : *textColor);

  // Draw to texture
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);

  // Adjust position
  SDL_Rect textRect;

  SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);

  textRect.x = x - textRect.w / 2, textRect.y = y - textRect.h / 2;

  SDL_RenderCopy(renderer, texture, NULL, &textRect);
} */

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
// To kill the programm
void terminate() {
  SDL_DestroyTexture(background_Texture);
  // main window
  SDL_DestroyRenderer(main_renderer);
  SDL_DestroyWindow(main_window);

  SDL_Quit();
  exit(0);
}
