/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * BORDER                                                                      *
 * - Defines all functions related to border                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * We will create a border by two-rectangle approach, smaller one on the       *
 *  bigger one to create a border illusion.                                    *
 * Border thickness is defined, as a percentage relative to height, in         *
 *  "../config.h".                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BORDER_H
#define BORDER_H

#include "../SDL3/SDL.h"
#include "../config.h"

void BorderRender(SDL_Renderer *renderer);

#endif
