#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include <fileioc.h>
#include "gfx/traspr.h"
#include "loadSprites.h"
#include "functions.h"
#include "tiles.h"

#define TARGET_FRAMERATE 20
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

int main(void) {
	if (traspr_init() == 0) {return 1;}
	
	loadChunk(playerChunk, "a+");
	ti_Rewind(worldChunk);
    ti_Write(tile_air, 1, 64000, worldChunk);
	closeChunk(0);
	
	initGfx();
	decompressSprites();
	
	//the endless loop of pain and suffering (for the developer, anyways)
	
	loadChunk(1, "r+");
	do {
		clock_t frame_start = clock();
		
		getInput();
		renderWindow();
		
		clock_t frame_time = clock() - frame_start;
		do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME); //delays the main loop until it is time to render the next frame based on the target framerate
	} while(running);
	
    gfx_End();
	freeSprites();
	closeChunk(1);
    return 0;
}