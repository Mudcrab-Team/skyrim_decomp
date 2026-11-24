// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x5105f0 BGSBtrDB::DBTraits::Destroy
// Adapted bodies: BGSBtrDB::DBTraits::Destroy from fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:110 (see the header)
#include "BGSTerrainChunk_5105f0.h"

void BGSBtrDB::DBTraits::Destroy(BGSTerrainChunk*& a_chunk)
{
    if (a_chunk)
    {
        delete a_chunk;
    }
    a_chunk = nullptr;
}
