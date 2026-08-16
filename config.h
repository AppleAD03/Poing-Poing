#ifndef CONFIG_H
#define CONFIG_H

#include <SDL3/SDL_video.h>

#define WINDOW_TITLE		"Poing Poing"
#define WINDOW_WIDTH		1280
#define WINDOW_HEIGHT		720
#define WINDOW_FLAG		0

//#fff4d1 peach white
//#706d64 peach grey
//#82ff82 light green
//#ff8282 light red

//#d3ffd1 pastel flush green
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

#define BUTTON_SIZE		0.7	//percentage w.r.t menu thickness
#define BUTTON_PLAY_COLOR_R	150
#define BUTTON_PLAY_COLOR_G	255
#define BUTTON_PLAY_COLOR_B	130
#define BUTTON_PLAY_COLOR_A	255
#define BUTTON_PAUSE_COLOR_R	255
#define BUTTON_PAUSE_COLOR_G	150
#define BUTTON_PAUSE_COLOR_B	130
#define BUTTON_PAUSE_COLOR_A	255

//#21db91 dull spring green
#define TRIANGLE_COLOR_R	0.1294
#define TRIANGLE_COLOR_G	0.8588
#define TRIANGLE_COLOR_B	0.5686
#define TRIANGLE_COLOR_A	1.0

#define TRIANGLE_SIZE		0.2	//percentage w.r.t arena_height/2; default size
#define TRIANGLE_PICK_BOX_SIZE	0.1	//percentage w.r.t aerne_height/2
#define TRIANGLE_PB_COLOR_R	255
#define TRIANGLE_PB_COLOR_G	255
#define TRIANGLE_PB_COLOR_B	255
#define TRIANGLE_PB_COLOR_A	127

#define CAP			5

#endif