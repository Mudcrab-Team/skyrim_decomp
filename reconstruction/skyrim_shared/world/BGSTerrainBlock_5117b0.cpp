// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5117b0 BGSTerrainBlock::SetBlockFlag
// Adapted bodies: none
#include "BGSTerrainBlock_5117b0.h"

void BGSTerrainBlock::SetBlockFlag()
{
    if (node0) {
        node0->flags |= 1u;
    }
    if (node1) {
        node1->flags |= 1u;
    }
}
