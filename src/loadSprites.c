#include <compression.h>
#include <graphx.h>
#include "gfx/traspr.h"

gfx_sprite_t *spr_guide1;
gfx_sprite_t *spr_debugAir;



void decompressSprites(void) {
	spr_guide1 = gfx_MallocSprite(spr_guide1_width, spr_guide1_height);
	zx0_Decompress(spr_guide1, spr_guide1_compressed);
	
	spr_debugAir = gfx_MallocSprite(spr_debugAir_width, spr_debugAir_height);
	zx0_Decompress(spr_debugAir, spr_debugAir_compressed);
}


void freeSprites(void) {
	free(spr_guide1);
	free(spr_debugAir);
}