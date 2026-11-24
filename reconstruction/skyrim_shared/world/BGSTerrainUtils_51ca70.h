// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUtils.cpp:92
// BGSTerrainUtils, BGSTerrainUtils::BuildLocalTerrainMeshFileName: SIBLING(fo4-private@1b765c70, author-permission)
// BSsprintf: GUESS(medium); name from the sibling body, declared outside the permitted folders
#pragma once

#include <cstdint>
#include <cstddef>

int BSsprintf(char* a_buffer, std::size_t a_bufferLen, const char* a_format, ...);

class BGSTerrainUtils
{
public:
    static void BuildLocalTerrainMeshFileName(char* a_buffer, unsigned int a_bufferLen, const char* a_worldName, short a_cellX, short a_cellY);
};
