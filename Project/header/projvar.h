#ifndef PROJVAR_H
#define PROJVAR_H

// global defines
#define DELAY 1000 // delay in milliseconds

// here are all global variables
extern const int TARGET_FPS;
extern const int FRAME_DELAY;

// std window size
extern const int WINDOW_WIDTH_std;
extern const int WINDOW_HEIGHT_std;

// changeable window size
extern int window_width;
extern int window_height;

// bools
extern bool is_main_closed;
extern bool is_popup_opened;
extern bool is_popup_closed;

#endif
