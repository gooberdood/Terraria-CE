#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include "gfx/traspr.h"
#include "functions.h"
#include "loadSprites.h"

int inGame = true;
int startUp = true;

//initialize gfx / set up
void initGfx(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();
	//sets palette and transparent color
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
	gfx_SetTextConfig(gfx_text_clip);
}


void getInput(void) {
	//scans the keypad, then checks inputs
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
}


//renders graphics to screen
void renderWindow(void) {

	do {
		gfx_FillScreen(1);
		gfx_Sprite_NoClip(goober, (320 - goober_width) / 2, (240 - goober_height) / 2);
		gfx_SwapDraw();
	} while(startUp == true;);

	gfx_SwapDraw();
}