#include <compression.h>
#include <graphx.h>
#include "gfx/traspr.h"

gfx_sprite_t *goober;

//decompresses sprites
void decompressSprites(void) {
	goober = gfx_MallocSprite(goober_width, goober_height);
	zx0_Decompress(goober, goober_compressed);
}