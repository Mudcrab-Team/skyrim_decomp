// Source exposure: mixed
// Code origin: DetachAll written from the target listing plus public declarations; KillAll adapted from the anonymous sibling and public declarations.
// Adapted bodies: GridCellArray::KillAll (fo4-private, see the Sibling source line)
// GridCellArray::KillAll: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:140
// GridCellArray, GridArray, GridCellArray::GetCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GridCellArray.h, include/RE/G/GridArray.h.
// names: GUESS(low); unknown member and method names are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x227280 GridCellArray::KillAll
// 0x227970 GridCellArray::DetachAll
#include "GridCellArray.h"
void GridCellArray::KillAll() { GridArray::KillAll(); if (dataHandler->IsClearing()) TESObjectCELL::KillStatics(); }

void GridCellArray::DetachAll()
{
	for (unsigned i = 0; i < length; ++i) {
		for (unsigned j = 0; j < length; ++j) {
			TESObjectCELL* cell = *GetCellSlot(i, j);
			if (cell) {
				cell->DetachAll();
			}
		}
	}
}
