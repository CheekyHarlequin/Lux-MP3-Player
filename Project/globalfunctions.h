#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
// here are all global functions

// from render-main.window.c
void render_main();

// from helpfull-functions.c
/*void drawText();*/
SDL_Texture *loadTexture(char *path, SDL_Renderer *renderer);

void terminate();
#endif
