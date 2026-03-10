#include <graphx.h>
#include <math.h>
#include "gfx/traspr.h"
#include "loadSprites.h"
#include "chunkManager.h"
#include "tiles.h"
#ifndef GET_INPUT_H
#define GET_INPUT_H

extern int running;
extern float playerX;
extern float playerY;
extern int cursorX;
extern int cursorY;
extern int playerChunk;
extern float playerSpeed;

void getInput(void);
void renderWindow(void);
void initGfx(void);

#endif