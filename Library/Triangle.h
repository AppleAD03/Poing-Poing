/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * TRIANGLE                                                                    *
 * - Defines all functions related to triangle                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Triagnle is made of 3 SDL_Vertex and will be rendered using SDL_Geometry.   *
 * It has centroid, linear velocity and angular velocity at any point in time. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../SDL3/SDL.h"
#include "../config.h"

typedef struct{
	SDL_Vertex v[3];
	SDL_FPoint centroid;
	SDL_FPoint linear_vel;
	float angular_vel;
}Triangle;

void TriangleInit(Triangle *tri);
void TriangleUpdate(Triangle *tri, Uint64 *now, Uint64 *then);
void TriangleRender(SDL_Renderer *renderer, Triangle *tri);

#endif