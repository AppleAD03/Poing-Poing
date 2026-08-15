#include "Border.h"

static void RenderBorder(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(
		 renderer
		,BORDER_COLOR_R
		,BORDER_COLOR_G
		,BORDER_COLOR_B
		,BORDER_COLOR_A
	); 
	SDL_RenderClear(renderer);
	SDL_FRect arena;
	arena.x = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.y = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.w = WINDOW_WIDTH - 2 * WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.h = WINDOW_HEIGHT - WINDOW_HEIGHT * (BORDER_MENU_THICKNESS + BORDER_MENU_THICKNESS);
	SDL_SetRenderDrawColor(
		 renderer
		,ARENA_COLOR_R
		,ARENA_COLOR_G
		,ARENA_COLOR_B
		,ARENA_COLOR_A
	);
	SDL_RenderFillRect(renderer, &arena);
}

static void RenderButton(SDL_Renderer *renderer){

}

void BorderRender(SDL_Renderer *renderer){
	RenderBorder(renderer);
}