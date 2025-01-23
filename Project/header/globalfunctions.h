#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
// here are all global functions


int initialize_SDL();
void initialize_all();
// from render-main.window.c
void render_main();
void initialize_buttons();
void load_main_textures();
void initialize_all_textures();

//from button-handling.c
void handle_button_pressed(int pressed_bttn);


int main_window_io();

// from helpfull-functions.c
/*void drawText();*/
SDL_Texture *loadTexture(char *path, SDL_Renderer *renderer);

void terminate();
#endif
