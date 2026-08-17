#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void TriangleInit(Triangle *tri){
	SDL_zeroa(tri->v);
	for(int i=0; i<3; i++){
		tri->v[i].color.r = TRIANGLE_COLOR_R;
		tri->v[i].color.g = TRIANGLE_COLOR_G;
		tri->v[i].color.b = TRIANGLE_COLOR_B;
		tri->v[i].color.a = TRIANGLE_COLOR_A;
	}
	tri->linear_vel.x = 0.0;
	tri->linear_vel.y = 0.0;
	tri->angular_vel = M_PI/2;
	SDL_FRect arena;
	arena.x = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.y = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.w = WINDOW_WIDTH - 2 * WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.h = WINDOW_HEIGHT * (1 - BORDER_THICKNESS - BORDER_MENU_THICKNESS);
	float a = arena.h * TRIANGLE_SIZE / 2.0;
	SDL_FPoint arena_centre;
	arena_centre.x = arena.x + arena.w/2.0;
	arena_centre.y = arena.y + arena.h/2.0;
	for(int i=0; i<3; i++){
		tri->p[i].x = arena_centre.x;
		tri->p[i].y = arena_centre.y;
	}
	tri->p[0].x += 0;
	tri->p[0].y += a;
	tri->p[1].x += 1.7320508 * a / 2.0;
	tri->p[1].y += -a/2.0;
	tri->p[2].x += - 1.7320508 * a / 2.0;
	tri->p[2].y += -a/2.0;
	//tri->centroid.x = (1/3.0) * (tri->p[0].x + tri->v[1].x + tri->v[2].x);
	//tri->centroid.y = (1/3.0) * (tri->p[0].y + tri->v[1].y + tri->v[2].y);
	tri->centroid.x = 0;
	tri->centroid.y = 0;
	tri->angle = 0.0;
}

void TriangleUpdate(Triangle *tri, Uint64 *now, Uint64 *then){
	if( ((*now)-(*then)) >= CAP ){
		float t = ((*now)-(*then))/1000.0;
		tri->angle += t * tri->angular_vel;
		if( tri->angle >= (2 * M_PI) )
			tri->angle += - (2 * M_PI);
		tri->centroid.x += t * tri->linear_vel.x;
		tri->centroid.y += t * tri->linear_vel.y;
	SDL_FRect arena;
	arena.x = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.y = WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.w = WINDOW_WIDTH - 2 * WINDOW_HEIGHT * BORDER_THICKNESS;
	arena.h = WINDOW_HEIGHT * (1 - BORDER_THICKNESS - BORDER_MENU_THICKNESS);
	float a = arena.h * TRIANGLE_SIZE / 2.0;
	SDL_FPoint arena_centre;
	arena_centre.x = arena.x + arena.w/2.0;
	arena_centre.y = arena.y + arena.h/2.0;
		for(int i=0; i<3;i++){
			tri->v[i].position.x = (tri->p[i].x-arena_centre.x) * cosf(tri->angle) - (tri->p[i].y-arena_centre.y) * sinf(tri->angle);
			tri->v[i].position.y = (tri->p[i].x-arena_centre.x) * sinf(tri->angle) + (tri->p[i].y-arena_centre.y) * cosf(tri->angle);
			tri->v[i].position.x += tri->centroid.x;
			tri->v[i].position.y += tri->centroid.y;
			tri->v[i].position.x += arena_centre.x;
			tri->v[i].position.y += arena_centre.y;
		}
		*then = *now;
	}
}

void TriangleRender(SDL_Renderer *renderer, Triangle *tri){
	SDL_RenderGeometry(renderer, NULL, tri->v, 3, NULL, 0);
}