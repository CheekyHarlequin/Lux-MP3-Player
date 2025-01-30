#include "header/Lux-MP3-Player.h"
#include "header/buttons.h"

SDL_Color textColor = {255, 255, 255, 255}; // white text
int scroll_offset = 0;
int song_item_height; // calc dynamically
int max_scroll_offset = 0;

// Original screen size
const int ORIGINAL_WINDOW_WIDTH = 1920;
const int ORIGINAL_WINDOW_HEIGHT = 1080;

SDL_Rect original_button_rects[NUM_OF_BUTTONS] = {
    {710, 845, 75, 100}, {710, 845, 75, 100},  {610, 845, 75, 100},
    {810, 845, 75, 100}, {1330, 845, 75, 100}, {1330, 845, 75, 100},
    {510, 845, 75, 100}};

SDL_Rect song_display_rect = {50, 100, 100, 100}; // x, y, width, height

// Function prototypes
void handle_window_resize(int new_width, int new_height);
void render_music_list(SDL_Renderer *renderer, SDL_Rect display_rect,
                       int scroll_offset);

bool get_initial_display_state(int index);

void render_all_buttons();
const char *get_image_path(int index);
void update_button_rects(int window_width, int window_height);
// helpfull render main functions
void load_main_textures();
void render_main_textures();

void update_rect_size(SDL_Rect *rect, int window_width, int window_height);
void update_main_rects(int window_width, int window_height);
void update_rect_pos(SDL_Rect *rect);
void renderButtons(SDL_Renderer *main_renderer);

SDL_Texture *background_Texture = NULL;
SDL_Texture *main_UI_Texture = NULL;

SDL_Rect background_Rect;
SDL_Rect main_UI_Rect;
int window_width_new = 1920;
int window_height_new = 1080;

void render_main() {
  // Aktualisiere die Positionen der Hintergründe
  update_rect_pos(&background_Rect);
  update_rect_pos(&main_UI_Rect);

  // Setze die Renderfarbe auf Schwarz (optional, wenn Hintergrund nicht das
  // gesamte Fenster füllt)
  SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);

  // Aktuelle Fenstergröße abrufen
  SDL_GetWindowSize(main_window, &window_width_new, &window_height_new);

  // UI-Elemente an die neue Fenstergröße anpassen
  update_main_rects(window_width_new, window_height_new);
  update_button_rects(window_width_new, window_height_new);

  // Falls notwendig, Fenstergrößenänderung verarbeiten
  handle_window_resize(window_width_new, window_height_new);

  // Bildschirm löschen
  SDL_RenderClear(main_renderer);

  // Hintergrund und Haupt-UI rendern
  render_main_textures();

  // Buttons rendern
  renderButtons(main_renderer);

  // Musikliste rendern
  render_music_list(main_renderer, song_display_rect, scroll_offset);
}

void load_main_textures() {
  background_Texture =
      loadTexture("main-window-textures/background.png", main_renderer);
  main_UI_Texture =
      loadTexture("main-window-textures/UI-MW.png", main_renderer);
}

void render_main_textures() {
  SDL_RenderCopy(main_renderer, background_Texture, NULL, &background_Rect);
  SDL_RenderCopy(main_renderer, main_UI_Texture, NULL, &main_UI_Rect);
}

void update_main_rects(int window_width, int window_height) {
  update_rect_size(&background_Rect, window_width, window_height);
  update_rect_size(&main_UI_Rect, window_width, window_height);
}

void update_rect_size(SDL_Rect *rect, int window_width, int window_height) {
  rect->w = window_width;
  rect->h = window_height;
}

void update_rect_pos(SDL_Rect *rect) {
  rect->y = 0;
  rect->x = 0;
}

void initialize_buttons(SDL_Renderer *renderer) {
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    buttons[i] =
        createButton(original_button_rects[i].x, original_button_rects[i].y,
                     original_button_rects[i].w, original_button_rects[i].h,
                     renderer, get_image_path(i), get_initial_display_state(i));
  }
}

// Helper functions to get image path and display state
const char *get_image_path(int index) {
  switch (index) {
  case 0:
    return "main-window-textures/play.png";
  case 1:
    return "main-window-textures/pause.png";
  case 2:
    return "main-window-textures/last-button.png";
  case 3:
    return "main-window-textures/next-button.png";
  case 4:
    return "main-window-textures/replay-off.png";
  case 5:
    return "main-window-textures/replay-on.png";
  case 6:
    return "main-window-textures/List.png";
  default:
    return "";
  }
}

bool get_initial_display_state(int index) { return (index != 1 && index != 5); }

// to render buttons
void renderButtons(SDL_Renderer *main_renderer) {
  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    if (buttons[i].to_display) {
      SDL_RenderCopy(main_renderer, buttons[i].texture, NULL, &buttons[i].rect);
    }
  }
}

void update_button_rects(int window_width, int window_height) {
  float width_ratio = (float)window_width / (float)ORIGINAL_WINDOW_WIDTH;
  float height_ratio = (float)window_height / (float)ORIGINAL_WINDOW_HEIGHT;

  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    buttons[i].rect.x = original_button_rects[i].x * width_ratio;
    buttons[i].rect.y = original_button_rects[i].y * height_ratio;
    buttons[i].rect.w = original_button_rects[i].w * width_ratio;
    buttons[i].rect.h = original_button_rects[i].h * height_ratio;
  }
}
void render_music_list(SDL_Renderer *renderer, SDL_Rect display_rect,
                       int scroll_offset) {
  int y_position = display_rect.y - scroll_offset;
  SDL_RenderSetClipRect(renderer, &display_rect);

  for (int i = 0; i < total_songs; ++i) {
    SDL_Rect text_rect = {display_rect.x + 5, y_position, display_rect.w - 10,
                          song_item_height}; // Kleine Ränder hinzufügen

    // Nur rendern, wenn innerhalb des display_rect
    if (text_rect.y + text_rect.h > display_rect.y &&
        text_rect.y < display_rect.y + display_rect.h) {
      const char *full_title = music_array[i].title;
      char truncated_title[256];
      strncpy(truncated_title, full_title, sizeof(truncated_title) - 1);
      truncated_title[sizeof(truncated_title) - 1] = '\0';

      int text_width = 0, text_height = 0;
      TTF_SizeText(defaultFont, truncated_title, &text_width, &text_height);

      // Überprüfen, ob der Text breiter ist als der verfügbare Platz
      if (text_width > text_rect.w) {
        // Ellipse hinzufügen
        const char *ellipsis = "...";
        int ellipsis_width = 0;
        TTF_SizeText(defaultFont, ellipsis, &ellipsis_width, NULL);

        int max_width = text_rect.w - ellipsis_width;
        int len = strlen(truncated_title);

        // Text kürzen, bis er passt
        while (len > 0) {
          truncated_title[len - 1] = '\0'; // Letztes Zeichen entfernen
          len--;

          // Neue Textbreite messen
          TTF_SizeText(defaultFont, truncated_title, &text_width, NULL);

          if (text_width <= max_width) {
            // Ellipse hinzufügen
            strncat(truncated_title, ellipsis,
                    sizeof(truncated_title) - strlen(truncated_title) - 1);
            break;
          }
        }

        if (len == 0) {
          // Wenn kein Platz ist, nur Ellipse anzeigen
          strncpy(truncated_title, ellipsis, sizeof(truncated_title));
        }
      }

      // Text rendern
      SDL_Surface *text_surface =
          TTF_RenderText_Solid(defaultFont, truncated_title, textColor);
      if (text_surface == NULL) {
        printf("Text konnte nicht gerendert werden: %s\n", TTF_GetError());
        continue;
      }

      SDL_Texture *text_texture =
          SDL_CreateTextureFromSurface(renderer, text_surface);
      SDL_FreeSurface(text_surface);
      if (text_texture == NULL) {
        printf("Textur konnte nicht erstellt werden: %s\n", SDL_GetError());
        continue;
      }

      // Text zeichnen
      SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
      SDL_DestroyTexture(text_texture);
    }
    y_position += song_item_height;
  }

  SDL_RenderSetClipRect(renderer, NULL);
}

void handle_window_resize(int new_width, int new_height) {
  // Aktualisiere das Anzeige-Rechteck für die Songliste
  song_display_rect.w = new_width * RELATIVE_WIDTH_FACTOR;
  song_display_rect.h = new_height * RELATIVE_HEIGHT_FACTOR;
  song_display_rect.x = new_width - song_display_rect.w - MARGIN_RIGHT;
  song_display_rect.y = new_height - song_display_rect.h - MARGIN_BOTTOM;

  // Aktualisiere die Größe der Buttons und andere UI-Elemente entsprechend
  update_main_rects(new_width, new_height);
  update_button_rects(new_width, new_height);

  // Aktualisiere die Höhe der Listenelemente
  song_item_height = new_height * ITEM_HEIGHT_FACTOR;

  // Aktualisiere den maximalen Scroll-Offset
  int total_height = total_songs * song_item_height;
  max_scroll_offset = total_height > song_display_rect.h
                          ? total_height - song_display_rect.h
                          : 0;

  // Stelle sicher, dass der Scroll-Offset innerhalb der neuen Grenzen liegt
  if (scroll_offset > max_scroll_offset) {
    scroll_offset = max_scroll_offset;
  }
}

void initialize_all_textures() {
  initialize_buttons(main_renderer);
  load_main_textures();
}
