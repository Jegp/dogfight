#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <emscripten.h>

#include "Environment.h"
#include "Game.h"

int x = 0;
int y = 0;
SDL_Surface *screen;

void main_loop() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: x++; break;
            case SDLK_LEFT: x--; break;
            case SDLK_UP: y--; break;
            case SDLK_DOWN: y++; break;
            default: printf("Other key"); break;
        }
      default: printf("Event"); break;
    }
  }

  // Clears the screen
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  
  // fill stuff
  SDL_Rect rect = { x, y, 175, 125 };
  SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, 0x22, 0x22, 0xff, 0xff));
  
}

int main(int argc, char **argv) {
#if EMSCRIPTEN
  // include GL stuff, to check that we can compile hybrid 2d/GL apps
  extern void glBegin(int mode);
  extern void glBindBuffer(int target, int buffer);
  if (argc == 9876) {
    glBegin(0);
    glBindBuffer(0, 0);
  }

  // init main loop
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);

  Environment * env;
  env->surface = screen;
  Game * game = new Game(env);

  printf("Init: %d\n", TTF_Init());

  emscripten_set_main_loop(main_loop, 30, 1);
#endif
  /*
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);

  printf("Init: %d\n", TTF_Init());

  TTF_Font *font = TTF_OpenFont("sans-serif", 40);
  printf("Font: %p\n", font);

  SDL_Color color = { 0xff, 0x99, 0x00, 0xff };

  SDL_Surface *text = TTF_RenderText_Solid(font, "hello orange world", color);

  SDL_Color color2 = { 0xbb, 0, 0xff, 0xff };
  SDL_Surface *text2 = TTF_RenderText_Solid(font, "a second line, purple", color2);

  // render
  SDL_Rect dest = { 0, 50, 0, 0 };
  SDL_BlitSurface (text, NULL, screen, NULL);
  dest.y = 100;
  SDL_BlitSurface (text2, NULL, screen, &dest);

  // fill stuff
  SDL_Rect rect = { 200, 200, 175, 125 };
  SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, 0x22, 0x22, 0xff, 0xff));

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
      printf("Loop");
    switch (event.type) {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: printf("Right"); break;
            default: printf("Other key"); break;
        }
      default: printf("Event"); break;
    }
  }

  SDL_Flip(screen); 

  SDL_LockSurface(screen);

  int width, height, isFullscreen;
  emscripten_get_canvas_size(&width, &height, &isFullscreen);

  if (width != 600 && height != 450)
  {
    printf("error: wrong width/height\n");
    abort();
  }

  int sum = 0;
  for (int i = 0; i < screen->h; i++) {
    sum += *((char*)screen->pixels + i*screen->w*4 + i*4 + 0);
  }
  printf("Sum: %d\n", sum);

  printf("you should see two lines of text in different colors and a blue rectangle\n");

  SDL_UnlockSurface(screen);
  
  SDL_Quit();

  printf("done.\n");

  int result = sum > 3000 && sum < 5000; // varies a little on different browsers, font differences?
  REPORT_RESULT();
  */

  return 0;
}

