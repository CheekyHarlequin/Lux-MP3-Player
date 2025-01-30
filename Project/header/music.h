#ifndef MUSIC_H
#define MUSIC_H

// defines
#define MAX_SONGS 250

// Music functions
int initialize_music(const char *folder_path);
void play_music(int index, int repeats);
void free_music();


//music variables
typedef struct {
    Mix_Music *music;
    char title[256]; // Assumption: song-titles are 256 chars long at most
} Song;


extern Song music_array[MAX_SONGS];
extern int total_songs;
extern int current_music_index;
extern int repeats_on_off;
extern bool has_started_once;
extern int scroll_offset;
#endif
