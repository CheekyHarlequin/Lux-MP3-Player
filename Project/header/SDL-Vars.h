#ifndef SDL_VARS_H
#define SDL_VARS_H

#include "projectlibs.h"
//Font
extern TTF_Font *defaultFont;
//For main window
extern SDL_Renderer *main_renderer;
extern SDL_Window *main_window;

// main window textures
extern SDL_Texture *background_Texture;
extern SDL_Texture *main_UI_Texture;

// main window rects
extern SDL_Rect background_Rect;
extern SDL_Rect main_UI_Rect;


// for List
extern SDL_Rect song_display_rect;
// For Events
extern SDL_Event main_event;

extern Mix_Music *bgm;
#endif
