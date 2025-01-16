#ifndef BUTTON_H
#define BUTTON_H

#include "projectlibs.h"

// structs for buttons
typedef struct {
    SDL_Rect rect;          // pos and size of button
    SDL_Texture *texture;   // Textur of button
} Button;

// Funktion zur Initialisierung eines Knopfes
Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer, const char *image_path);
void updateButtonRect(Button *button, int windowWidth, int windowHeight);

// Funktion zum Rendern eines Knopfes
void renderButton(Button button, SDL_Renderer *renderer, int window_width,
                  int window_height);

#endif
