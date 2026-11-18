// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GridCellArray::KillAll: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:140
// GridCellArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GridCellArray.h and include/RE/G/GridArray.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x227280 GridCellArray::KillAll
#include "GridCellArray.h"
void GridCellArray::KillAll() { GridArray::KillAll(); if (dataHandler->IsClearing()) TESObjectCELL::KillStatics(); }
