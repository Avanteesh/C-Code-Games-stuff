#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

// game board dimensions
#define GAME_BOARD_HEIGHT 800
#define GAME_BOARD_WIDTH 1100

// home postion of the block
#define homepositionX 20
#define homepositionY 20
// speed of the block
#define Block_Speed 5

bool game_Running = false;

typedef struct {
    float x;
    float y;
    float block_height;
    float block_width;
} BLOCK;

// glbal variable block
BLOCK block;

const char display_title[20] = "Bock Game";

SDL_Window * Window;
SDL_Renderer * Renderer;

bool intialize_Window(void)  {
      
      if (SDL_Init(SDL_INIT_EVERYTHING) != 0)  {
            fprintf(stderr, "Error occurred in initializing\n");
            return true;
      }
      
      Window = SDL_CreateWindow(
            display_title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            GAME_BOARD_WIDTH,
            GAME_BOARD_HEIGHT,
            SDL_WINDOW_SHOWN
      );
      
      if (!Window)  {
           fprintf(stderr, "Erro occurred in displaying GUI\n");
           return false;
      }
  
      Renderer = SDL_CreateRenderer(Window, -1, 0);
      
      if (!Renderer)  {
            fprintf(stderr, "Failed to render graphics\n");
            return false;
      }
      
      return true;
}

void Process_Input()  {

      SDL_Event event;
      SDL_PollEvent(&event);
      
      switch(event.type)  {
          case SDL_QUIT:
              game_Running = false;
              break;
              
          case SDL_KEYDOWN:
              if (event.key.keysym.sym == SDLK_ESCAPE)  {
                      game_Running = false;
              }
              break;
      }
}

void updatePosition()  {
      SDL_Event event;
      SDL_PollEvent(&event);
      
      // rendering keyboard events
      switch(event.key.keysym.sym)  {
          // if arrow key is Up then move the block up
          case SDLK_UP:
              block.y -= Block_Speed;
              break;
              
          // if arrow key is Down then move the block below
          case SDLK_DOWN:
              block.y += Block_Speed;
              break;
          
          // if arrow key is left make the block move left
          case SDLK_LEFT:
              block.x -= Block_Speed;
              break;
          
          // if arrow key is right make the block move right
          case SDLK_RIGHT:
              block.x += Block_Speed;
              break;
      }
}

void Setup()  {
    block.x = homepositionX;
    block.y = homepositionY;
    block.block_height = 50;
    block.block_width = 50;
}

void Render()  {
    
    SDL_SetRenderDrawColor(Renderer, 210, 28, 49, 255); 
    SDL_RenderClear(Renderer);
    
    SDL_Rect block_object = {
          (int)block.x, (int)block.y,
          (int)block.block_width, (int)block.block_height
    };
    
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Renderer, &block_object);
    SDL_RenderPresent(Renderer);
}

void destroy_window();

int main(void)  {
      
      // testing 
      // printf("all good\n");
      // Process_Input();
      bool GameRun = intialize_Window();
      
      Setup();
      
      while (GameRun)  {
          Process_Input();
          Render();
          updatePosition();
      }
      
  
      return 0;
}

void destroy_window()  {
      SDL_DestroyRenderer(Renderer);
      SDL_DestroyWindow(Window);
      SDL_Quit();
}


















