#include "projectlibs.h"
#include "projvar.h"

SDL_Renderer *mainrenderer;
SDL_Window *mainwindow;
TTF_Font *defaultFont;

int main(int argc, char **argv) {

  /*
   * Initialises the SDL video subsystem (as well as the events subsystem).
   * Returns 0 on success or a negative error code on failure using
   * SDL_GetError().
   */
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a SDL window */
  mainwindow = SDL_CreateWindow(
      "Lux-MP3-Player",       /* Title of the SDL window */
      SDL_WINDOWPOS_CENTERED, /* Position x of the window */
      SDL_WINDOWPOS_CENTERED, /* Position y of the window */
      800,                    /* Width of the window in pixels */
      600,                    /* Height of the window in pixels */
      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL |
          SDL_WINDOW_MAXIMIZED); /* Additional flag(s) */

  /* Checks if window has been created; if not, exits program */
  if (mainwindow == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  /* Pauses all SDL subsystems for a variable amount of milliseconds */
  SDL_Delay(DELAY);

  /* Frees memory */
  SDL_DestroyWindow(mainwindow);

  /* Shuts down all SDL subsystems */
  SDL_Quit();

  return 0;
}
