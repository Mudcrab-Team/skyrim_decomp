// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: MapView::ClearAll.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bscore/memorymanager.cpp:11
// 0x2d5d00 MapView::ClearAll
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/memorymanager.cpp:398
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/memorymanager.cpp:362
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bscore/memorymanager.cpp:381
// Adapted helpers: ClearAll, operatordelete
#include "MapView_2d5d00.h"

void MapView::ClearAll()
{
    for (unsigned int bucket = 0; bucket < unk04; ++bucket)
    {
        while (unk08[bucket])
        {
            WeightedMapNode* node = unk08[bucket];
            unk08[bucket] = unk08[bucket]->unk00;
            slot4(node);
            slot6(node);
        }
    }
    unk0C = 0;
}
