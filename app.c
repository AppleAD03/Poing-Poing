#include <stdio.h>
#include <stdlib.h>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "config.h"
#include "Library/Border.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(
		 WINDOW_TITLE
		,WINDOW_WIDTH
		,WINDOW_HEIGHT
		,WINDOW_FLAG
		,&window
		,&renderer
	);
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if(event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate){
	SDL_SetRenderDrawColor(renderer, 55, 66, 66, SDL_ALPHA_OPAQUE);
	//BorderRender calls SDL_RenderClear
	BorderRender(renderer);
	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){

}