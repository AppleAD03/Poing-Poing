#include "Triangle.h"

void TriangleInit(Triangle *tri){
	SDL_zeroa(tri->v);
	for(int i=0; i<3; i++){
		tri->v[i].color.r = TRIANGLE_COLOR_R;
		tri->v[i].color.g = TRIANGLE_COLOR_G;
		tri->v[i].color.b = TRIANGLE_COLOR_B;
		tri->v[i].color.a = TRIANGLE_COLOR_A;
	}
	tri->linear_vel.x = 0;
	tri->linear_vel.y = 0;
	tri->angular_vel = 0.01;
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
		tri->v[i].position.x = arena_centre.x;
		tri->v[i].position.y = arena_centre.y;
	}
	tri->v[0].position.x += 0;
	tri->v[0].position.y += a;
	tri->v[1].position.x += 1.7320508 * a / 2.0;
	tri->v[1].position.y += -a/2.0;
	tri->v[2].position.x += - 1.7320508 * a / 2.0;
	tri->v[2].position.y += -a/2.0;
}

void TriangleUpdate(Triangle *tri, Uint64 *now, Uint64 *then){
	tri->centroid.x = (1/3.0) * (tri->v[0].position.x + tri->v[1].position.x + tri->v[2].position.x);
	tri->centroid.y = (1/3.0) * (tri->v[0].position.y + tri->v[1].position.y + tri->v[2].position.y);
	if( ((*now)-(*then)) >= CAP ){
		for(int i=0; i<3;i++){
			float vangx =  (tri->v[i].position.y - tri->centroid.y) * tri->angular_vel;
			float vangy = -(tri->v[i].position.x - tri->centroid.x) * tri->angular_vel;
			tri->v[i].position.x += CAP * tri->linear_vel.x;
			tri->v[i].position.x += CAP * vangx;
			tri->v[i].position.y += CAP * tri->linear_vel.y;
			tri->v[i].position.y += CAP * vangy;
		}
		*then = *now;
	}
}

void TriangleRender(SDL_Renderer *renderer, Triangle *tri){
	SDL_RenderGeometry(renderer, NULL, tri->v, 3, NULL, 0);
}