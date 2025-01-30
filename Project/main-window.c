#include "header/Lux-MP3-Player.h"

int main_window_io() {
  bool quit = false;

  while (!quit) {
    while (SDL_PollEvent(&main_event)) {
      switch (main_event.type) {
      case SDL_QUIT:
        terminate();
        break;
      case SDL_MOUSEBUTTONDOWN:
        int mouse_x = main_event.button.x;
        int mouse_y = main_event.button.y;

        // Überprüfen, ob der Klick innerhalb des song_display_rect war
        if (mouse_x >= song_display_rect.x &&
            mouse_x <= song_display_rect.x + song_display_rect.w &&
            mouse_y >= song_display_rect.y &&
            mouse_y <= song_display_rect.y + song_display_rect.h) {

          // Berechnen, welcher Song angeklickt wurde
          int relative_y = mouse_y - song_display_rect.y + scroll_offset;
          current_music_index = relative_y / song_item_height;

          if (current_music_index >= 0 && current_music_index < total_songs) {
            // Song abspielen
            play_music(current_music_index, repeats_on_off);
            buttons[1].to_display = true;
            buttons[0].to_display = false;
          }
        }
        SDL_GetMouseState(&mouse_x, &mouse_y);
        int pressed_button = get_pressed_button(mouse_x, mouse_y);
        printf("Mouse button pressed at (%d, %d)\n", mouse_x, mouse_y);
        printf("Pressed button index: %d\n", pressed_button);
        handle_button_pressed(pressed_button);
        break;
      case SDL_MOUSEWHEEL:
        if (main_event.wheel.y > 0) {
          scroll_offset -= song_item_height;
          if (scroll_offset < 0)
            scroll_offset = 0;
        } else if (main_event.wheel.y < 0) {
          scroll_offset += song_item_height;
          if (scroll_offset > max_scroll_offset)
            scroll_offset = max_scroll_offset;
        }
        break;
      }
    }

    render_main();
    SDL_RenderPresent(main_renderer);
  }

  return 1;
}
