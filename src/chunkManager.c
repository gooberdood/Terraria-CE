#include <fileioc.h>
#include "chunkManager.h"

int worldChunk;

void loadChunk(int chunk) {
	if (chunk == 1) {worldChunk = ti_Open("TRCHUNKA", "a+");}
	if (chunk == 2) {worldChunk = ti_Open("TRCHUNKB", "a+");}
	if (chunk == 3) {worldChunk = ti_Open("TRCHUNKC", "a+");}
	if (chunk == 4) {worldChunk = ti_Open("TRCHUNKD", "a+");}
	if (chunk == 5) {worldChunk = ti_Open("TRCHUNKE", "a+");}
	if (chunk == 6) {worldChunk = ti_Open("TRCHUNKF", "a+");}
	if (chunk == 7) {worldChunk = ti_Open("TRCHUNKG", "a+");}
	if (chunk == 8) {worldChunk = ti_Open("TRCHUNKH", "a+");}
	ti_Rewind(worldChunk);
}

void closeChunk(void) {
	if (ti_ArchiveHasRoomVar(worldChunk)) {
		ti_SetArchiveStatus(true, worldChunk);
	}
	ti_Close(worldChunk);
}