#include <stdio.h>
#include <stdlib.h>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#incldue <SDL3/SDL_main.h>

#include "config.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(
		 WINDOW_TITLE
		,WINDOW_WIDTH
		,WINDOW_HEIGHT
		,WINDOW_FLAG
		,window
		,renderer
	);
	return SDL_APP_CONTINUE
}