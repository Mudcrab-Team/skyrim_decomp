// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x5113c0 BGSTerrainChunk::OnLoadFinished
// Adapted bodies: BGSTerrainChunk::OnLoadFinished from fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:83 (see the header)
#include "BGSTerrainChunk_5113c0.h"

void BGSTerrainChunk::OnLoadFinished()
{
    bDoneLoading = 1;
    int cellY = pNode->sBaseCellY;
    int cellX = pNode->sBaseCellX;
    pNode->pManager->SetNeedsImmediateUpdate(cellX, cellY);
}
