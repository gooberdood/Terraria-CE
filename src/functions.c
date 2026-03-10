#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include "gfx/traspr.h"
#include "functions.h"
#include "tiles.h"

int running = true;
float playerX = 50; //player center X position in tiles
float playerY = 128; //player center Y position in tiles
int playerChunk = 1;
int playerXinPX; //PX is pixels
int playerYinPX;
float playerSpeed = .25;
int frameCount = 1;
int tileX;
int tileY;
int tileOffsetX;
int tileOffsetY;

void initGfx(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
	gfx_SetTextFGColor(2);
}


void getInput(void) {
	kb_Scan();
	
	if (kb_Data[6] & kb_Clear) {running = false;}
	if (kb_Data[7] & kb_Left) {playerX -= playerSpeed;}
	if (kb_Data[7] & kb_Right) {playerX += playerSpeed;}
	if (kb_Data[7] & kb_Up) {playerY -= playerSpeed;}
	if (kb_Data[7] & kb_Down) {playerY += playerSpeed;}
}


void renderWindow(void) {
	frameCount++;
	if(frameCount > 20) {frameCount = 0;}
	
	gfx_FillScreen(1);
	playerXinPX = playerX*8;
	playerYinPX = playerY*8;
	
	for (int i = playerXinPX; i >= 8; i=i-8) {
		tileOffsetX = i;
	}
	for (int i = playerYinPX; i >= 8; i=i-8) {
		tileOffsetY = i;
	}
	
	//x and y in the for loops points to the xy positions of the onscreen tiles, starting at the top left tile, left to right top to bottom
	for (int x = 0; x < 43; x++) {
		tileX = (x-1)*8-tileOffsetX;
		for (int y = 0; y < 33; y++) {
			tileY = (y-1)*8-tileOffsetY;
			if (tileX < 0 || tileX > 312 || tileY < 0 || tileY > 232) {
				gfx_TransparentSprite(spr_debugAir, tileX, tileY);
			}
			else {
				gfx_TransparentSprite_NoClip(spr_debugAir, tileX, tileY);
			}
		}
	}

	gfx_TransparentSprite_NoClip(spr_guide1, 152, 108);
	gfx_SetTextXY(1,1);
	gfx_PrintInt(frameCount, 1);
	gfx_SwapDraw();
}