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
	arena.h = WINDOW_HEIGHT * (1 - BORDER_THICKNESS - BORDER_MENU_THICKNESS);
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
	SDL_FRect button;
	float menu_thickness = WINDOW_HEIGHT * BORDER_MENU_THICKNESS;
	float border_thickness = WINDOW_HEIGHT * BORDER_THICKNESS;
	float button_thickness = menu_thickness * BUTTON_SIZE;
	button.x = (WINDOW_WIDTH - button_thickness)/2;
	button.y = WINDOW_HEIGHT - (1/2.0 + BUTTON_SIZE/2.0) * (menu_thickness);
	button.w = button_thickness;
	button.h = button_thickness;
	SDL_SetRenderDrawColor(
		 renderer
		,BUTTON_COLOR_R
		,BUTTON_COLOR_G
		,BUTTON_COLOR_B
		,BUTTON_COLOR_A
	);
	SDL_RenderFillRect(renderer, &button);
}

void BorderRender(SDL_Renderer *renderer){
	RenderBorder(renderer);
	RenderButton(renderer);
}