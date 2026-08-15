#ifndef CONFIG_H
#define CONFIG_H

#include <SDL3/SDL_video.h>

#define WINDOW_TITLE		"Poing Poing"
#define WINDOW_WIDTH		1280
#define WINDOW_HEIGHT		720
#define WINDOW_FLAG		0

//#fff4d1 peach white
//#706d64 peach grey
//#626d6e water dark grey
//#c4c4c4 cool dull white
//#21db91 dull spring green
#define BORDER_THICKNESS	0.05	//percentage w.r.t window size
#define BORDER_MENU_THICKNESS	0.1	//precentage w.r.t window size
#define BORDER_COLOR_R		112
#define BORDER_COLOR_G		109
#define BORDER_COLOR_B		100
#define BORDER_COLOR_A		255

#define ARENA_COLOR_R		255
#define ARENA_COLOR_G		244
#define ARENA_COLOR_B		209
#define ARENA_COLOR_A		255

#define BUTTON_SIZE		0.8	//percentage w.r.t menu thickness
#define BUTTON_COLOR_R		255
#define BUTTON_COLOR_G		244
#define BUTTON_COLOR_B		209
#define BUTTON_COLOR_A		255

#endif