// Most of the example is from
// https://lazyfoo.net/tutorials/SDL3/01-hello-sdl3/index2.php


#include <SDL3/SDL.h>

int main() {
  SDL_Window *window = NULL;
  const int screen_width = 800;
  const int screen_height = 600;

  SDL_Surface *surface = NULL;

  bool everything_is_fine = true;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log(
        "Ohnoes, something went horribly wrong while initializing video: %s\n",
        SDL_GetError());
    everything_is_fine = false;

  }

  else {
    if (window =
            SDL_CreateWindow("Hello, SDL3", screen_width, screen_height, 0);
        window == NULL) {
      SDL_Log("Ohnoes, something went horribly wrong while creating window: %s",
              SDL_GetError());
      everything_is_fine = false;
    } else {
      surface = SDL_GetWindowSurface(window);
    }
  }

  if (everything_is_fine) {
    bool game_is_running = true;
    SDL_Event event;
    SDL_zero(event);

    while (game_is_running) {
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
          game_is_running = false;
        }
      }
    }
  }

  SDL_DestroySurface(surface);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
