#include "header/Lux-MP3-Player.h"

Song music_array[MAX_SONGS];

int total_songs = 0;
int current_music_index = 0;
int repeats_on_off = 1;
bool has_started_once = false;

int initialize_music(const char *folder_path) {
  struct dirent *entry;
  DIR *dp = opendir(folder_path);

  if (dp == NULL) {
    printf("Dir can't be opened: %s\n", folder_path);
    return -1;
  }

  while ((entry = readdir(dp)) != NULL && total_songs < MAX_SONGS) {
    if (strstr(entry->d_name, ".mp3") != NULL) {
      char file_path[512]; // Puffer für den Dateipfad
      int ret = snprintf(file_path, sizeof(file_path), "%s/%s", folder_path,
                         entry->d_name);

      // check if path fits in puffer
      if (ret < 0 || ret >= sizeof(file_path)) {
        printf("Data-path too long!: %s/%s\n", folder_path, entry->d_name);
        continue;
      }

      music_array[total_songs].music = Mix_LoadMUS(file_path);
      if (music_array[total_songs].music == NULL) {
        printf("MP3 could not be loaded!: %s. SDL_mixer Error: %s\n", file_path,
               Mix_GetError());
        continue;
      }

      // save title
      strncpy(music_array[total_songs].title, entry->d_name,
              sizeof(music_array[total_songs].title) - 1);
      music_array[total_songs]
          .title[sizeof(music_array[total_songs].title) - 1] = '\0';

      total_songs++;
    }
  }

  closedir(dp);
  return 0;
}

void play_music(int index, int repeats) {
  if (index < 0 || index >= total_songs) {
    printf("Invalid index: %d\n", index);
    return;
  }

  if (Mix_PlayMusic(music_array[index].music, repeats) == -1) {
    printf("Music can't be played! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

void free_music() {
  for (int i = 0; i < total_songs; i++) {
    Mix_FreeMusic(music_array[i].music);
  }
  total_songs = 0;
}
