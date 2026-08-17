#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "config.h"
#include "Library/Border.h"
#include "Library/Triangle.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

Triangle tri;

bool menu_state = false;
bool mouse_down = false;
bool mouse_up = false;
bool wait = false;

Uint64 now=0, then=0;

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
	SDL_SetRenderVSync(renderer, 1);
	TriangleInit(&tri);
	now = SDL_GetTicks();
	then = now;
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if(event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;
	if(event->type == SDL_EVENT_MOUSE_BUTTON_DOWN){
		SDL_FRect rect = BorderGetButton();
		SDL_FPoint point;
		SDL_MouseButtonFlags mouse = SDL_GetMouseState(&point.x, &point.y);
		if(SDL_PointInRectFloat(&point, &rect))
			mouse_down = true;
		wait = true;
	}
	if(event->type == SDL_EVENT_MOUSE_BUTTON_UP){
		SDL_FRect rect = BorderGetButton();
		SDL_FPoint point;
		SDL_MouseButtonFlags mouse = SDL_GetMouseState(&point.x, &point.y);
		if(SDL_PointInRectFloat(&point, &rect))
			mouse_up = true;
		wait = false;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate){
	now = SDL_GetTicks();
		//BorderRender calls SDL_RenderClear
	if(mouse_down && mouse_up)
		menu_state = !menu_state;
	if(!wait){
		mouse_up = false;
		mouse_down = false;
	}
	BorderRender(renderer, menu_state);
	TriangleUpdate(&tri, &now, &then);
	TriangleRender(renderer, &tri);
	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){

}