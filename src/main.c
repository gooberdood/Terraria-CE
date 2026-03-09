//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "gfx/traspr.h"
#include "loadSprites.h"
#include "functions.h"

//frame limit
#define TARGET_FRAMERATE 20
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

//main stuffz
int main(void) {
	
	//setup / initialization
	if (traspr_init() == 0) {return 1;}
	initGfx();
	
	//decompressing sprites
	decompressSprites();
	
	//the endless loop of pain and suffering (for the developer, anyways)
	do {
		clock_t frame_start = clock();
		
		getInput();
		renderWindow();
		
		clock_t frame_time = clock() - frame_start;
		do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME);
	} while(running);
	
    gfx_End();
	freeSprites();
    return 0;
}