#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include <fileioc.h>
#include "gfx/traspr.h"
#include "functions.h"
#include "tiles.h"
#include "chunkManager.h"
#include "loadSprites.h"

int running = true;
float playerX = 50; //player center X position in tiles
float playerY = 128; //player center Y position in tiles
int playerChunk = 1;
int playerXinPX; //PX is pixels
int playerYinPX;
float playerSpeed = .25;
int cursorX;
int cursorY;
int frameCount = 1;
int tileX;
int tileY;
int tileXinPX;
int tileYinPX;
int tileOffsetX;
int tileOffsetY;
uint8_t chunkTilePos;
int x;
int y;
int chunkTiles[42];

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
	tileOffsetX = playerXinPX&7;
	tileOffsetY = playerYinPX&7;
	
	//x and y in the for loops points to the xy positions of the onscreen tiles, starting at the top left tile, left to right top to bottom
	chunkTilePos = 9;
	for (y = 0; y < 33; y++) {
		tileY = y-1;
		tileYinPX = tileY*8-tileOffsetY;
		ti_Seek(chunkTilePos, SEEK_SET, worldChunk);
		
		ti_Read(chunkTiles, 1, 42, worldChunk);
		
		for (x = 0; x < 43; x++) {
			tileX = x-1;
			tileXinPX = tileX*8-tileOffsetX;
			
			if (tileXinPX < 1 || tileXinPX > 311 || tileYinPX < 1 || tileYinPX > 231) {
				if (chunkTiles[x] == 0) {
					gfx_TransparentSprite(spr_debugAir, tileXinPX, tileYinPX);
				}
			}
			else {
				if (chunkTiles[x] == 0) {
					gfx_TransparentSprite_NoClip(spr_debugAir, tileXinPX, tileYinPX);
				}
			}
		}
		chunkTilePos += 42;
	}
	

	gfx_TransparentSprite_NoClip(spr_guide1, 152, 108);
	gfx_SetTextXY(1,1);
	gfx_PrintInt(frameCount, 1);
	gfx_SwapDraw();
}