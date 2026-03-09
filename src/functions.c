#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include "gfx/traspr.h"
#include "functions.h"
#include "tiles.h"

int running = true;
float playerX = 50; //player center X position
float playerY = 128; //player foot Y position
int playerChunk = 1;

void initGfx(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
	gfx_SetTextFGColor(1);
}


void getInput(void) {
	kb_Scan();
	
	if (kb_Data[6] & kb_Clear) {running = false;}
}


void renderWindow(void) {
	gfx_FillScreen(1);
	gfx_TransparentSprite_NoClip(spr_guide1, 152, 108);
	gfx_SwapDraw();
}