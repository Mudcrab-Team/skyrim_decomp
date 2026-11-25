// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x51ca70 BGSTerrainUtils::BuildLocalTerrainMeshFileName
// Adapted bodies: BGSTerrainUtils::BuildLocalTerrainMeshFileName from fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUtils.cpp:92 (see the header)
#include "BGSTerrainUtils_51ca70.h"

void BGSTerrainUtils::BuildLocalTerrainMeshFileName(char* a_buffer, unsigned int a_bufferLen, const char* a_worldName, short a_cellX, short a_cellY)
{
    BSsprintf(a_buffer, a_bufferLen, "Data\\Meshes\\Terrain\\%s\\Local\\%s.%i.%i.BLT", a_worldName, a_worldName, a_cellX, a_cellY);
}
