#ifndef BUTTON_H
#define BUTTON_H

#include "projectlibs.h"

// structs for buttons
typedef struct {
    SDL_Rect rect;          // pos and size of button
    SDL_Texture *texture;
    bool to_display;// Textur of button
} Button;

// initialize button and update its pos
Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer, const char *image_path, bool shall_display);
void updateButtonRect(Button *button, int windowWidth, int windowHeight);

// To render buttons
void renderButton(Button *play_button, SDL_Renderer *main_renderer);


//All existing buttons
// #TODO maybe create Array for all buttons
extern Button play_button;
#endif
