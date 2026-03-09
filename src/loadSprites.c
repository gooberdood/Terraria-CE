#include <compression.h>
#include <graphx.h>
#include "gfx/traspr.h"

gfx_sprite_t *spr_tree;
gfx_sprite_t *spr_logo;
gfx_sprite_t *spr_relogic;

//decompresses sprites
void decompressSprites(void) {
	spr_tree = gfx_MallocSprite(spr_tree_width, spr_tree_height);
	zx0_Decompress(tree, tree_compressed);
	
	spr_logo = gfx_MallocSprite(spr_logo_width, spr_logo_height);
	zx0_Decompress(spr_logo, spr_logo_compressed);
	
	spr_relogic = gfx_MallocSprite(spr_relogic_width, spr_relogic_height);
	zx0_Decompress(spr_relogic, spr_relogic_compressed);
}

void freeSprites(void) {
	free(spr_tree);
	free(spr_logo);
	free(spr_relogic);
}