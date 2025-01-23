#include "header/Lux-MP3-Player.h"

void handle_button_pressed(int pressed_bttn) {
  switch (pressed_bttn) {
  case 0:
    printf("Button 0 (Play) pressed\n");
    buttons[0].to_display = false;
    buttons[1].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 1:
    printf("Button 1 (Pause) pressed\n");
    buttons[1].to_display = false;
    buttons[0].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 2:
    puts("Button 2 (last) pressed");
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 3:
    puts("Button 3 (next)pressed");
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 4:
    puts("button 4 (replay-off) pressed");
    buttons[4].to_display = false;
    buttons[5].to_display = true;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 5:
    puts("button 5 (replay-on) pressed");
    buttons[4].to_display = true;
    buttons[5].to_display = false;
    render_main();
    SDL_RenderPresent(main_renderer);
    SDL_Delay(500);
    break;
  case 6:
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
