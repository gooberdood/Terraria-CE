#include <fileioc.h>
#include "chunkManager.h"

int worldChunk;

void loadChunk(int chunk, char mode[]) {
	if (chunk == 1) {worldChunk = ti_Open("TRCHUNKA", mode);}
	if (chunk == 2) {worldChunk = ti_Open("TRCHUNKB", mode);}
	if (chunk == 3) {worldChunk = ti_Open("TRCHUNKC", mode);}
	if (chunk == 4) {worldChunk = ti_Open("TRCHUNKD", mode);}
	if (chunk == 5) {worldChunk = ti_Open("TRCHUNKE", mode);}
	if (chunk == 6) {worldChunk = ti_Open("TRCHUNKF", mode);}
	if (chunk == 7) {worldChunk = ti_Open("TRCHUNKG", mode);}
	if (chunk == 8) {worldChunk = ti_Open("TRCHUNKH", mode);}
	ti_Rewind(worldChunk);
}

void closeChunk(int quit) {
	if (quit) {
		if (ti_ArchiveHasRoomVar(worldChunk)) {
			ti_SetArchiveStatus(true, worldChunk);
		}
	}
	ti_Close(worldChunk);
}