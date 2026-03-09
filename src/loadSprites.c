#include <compression.h>
#include <graphx.h>
#include "gfx/traspr.h"

gfx_sprite_t *spr_guide1;


void decompressSprites(void) {
	spr_guide1 = gfx_MallocSprite(spr_guide1_width, spr_guide1_height);
	zx0_Decompress(spr_guide1, spr_guide1_compressed);
}


void freeSprites(void) {
	free(spr_guide1);
}