#include "header/Lux-MP3-Player.h"

void handle_button_pressed(int pressed_bttn) {
  switch (pressed_bttn) {

  case 0: // play song
    if (!has_started_once) {
      play_music(current_music_index, repeats_on_off);
      has_started_once = true;
    } else {
      Mix_ResumeMusic();
    }
    buttons[0].to_display = false;
    buttons[1].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 1: // pause song
    Mix_PauseMusic();
    buttons[1].to_display = false;
    buttons[0].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 2: // last song
    current_music_index = (current_music_index == 0)
                              ? total_songs - 1
                              : (current_music_index - 1);
    if (buttons[5].to_display) {
      repeats_on_off = 1;
      buttons[4].to_display = true;
      buttons[5].to_display = false;
    }
    if (buttons[0].to_display) {
      buttons[0].to_display = false;
      buttons[1].to_display = true;
    }

    play_music(current_music_index, repeats_on_off);
    puts("Button 2 (last) pressed");
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 3: // next song
    current_music_index = (current_music_index == total_songs - 1)
                              ? 0
                              : (current_music_index + 1);
    if (buttons[5].to_display) {
      repeats_on_off = 1;
      buttons[4].to_display = true;
      buttons[5].to_display = false;
    }
    if (buttons[0].to_display) {
      buttons[0].to_display = false;
      buttons[1].to_display = true;
    }
    play_music(current_music_index, repeats_on_off);
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 4: // set replay on
    puts("button 4 (replay-off) pressed");
    repeats_on_off = -1;
    play_music(current_music_index, repeats_on_off);
    buttons[4].to_display = false;
    buttons[5].to_display = true;

    buttons[0].to_display = false;
    buttons[1].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 5: // set replay off
    puts("button 5 (replay-on) pressed");
    repeats_on_off = 1;
    play_music(current_music_index, repeats_on_off);
    buttons[4].to_display = true;
    buttons[5].to_display = false;
    buttons[0].to_display = false;
    buttons[1].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;

  case 6: // List
    puts("buttons 6 (list) pressed");
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(50);
    break;

  default:
    printf("No button pressed\n");
    break;
  }
}
