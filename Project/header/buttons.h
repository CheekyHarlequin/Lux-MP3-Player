#ifndef BUTTON_H
#define BUTTON_H

#include "projectlibs.h"

#define NUM_OF_BUTTONS 7 // <-- 7 cause as of now, cause there are 7 buttons currently



// structs for buttons
typedef struct {
    SDL_Rect rect;          // pos and size of button
    SDL_Texture *texture;
    bool to_display;// Textur of button
} Button;


extern Button buttons[NUM_OF_BUTTONS];

// initialize button and update its pos
Button createButton(int x, int y, int w, int h, SDL_Renderer *renderer, const char *image_path, bool shall_display);
void updateButtonRect(Button *button, int windowWidth, int windowHeight);

// To render buttons
void renderButtons(SDL_Renderer *main_renderer);

int get_pressed_button(int x, int y);



#endif
