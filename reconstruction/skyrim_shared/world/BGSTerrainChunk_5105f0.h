// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:110
// BGSBtrDB, BGSBtrDB::DBTraits::Destroy, BGSTerrainChunk: SIBLING(fo4-private@1b765c70, author-permission)
// BGSBtrDB::DBTraits: GUESS(medium); name from the sibling body, declared outside the permitted folders
// unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSTerrainChunk
{
public:
    ~BGSTerrainChunk();

    std::uint8_t unknown00[0x28];  // 00
};
static_assert(sizeof(BGSTerrainChunk) == 0x28, "BGSTerrainChunk size");

class BGSBtrDB
{
public:
    class DBTraits
    {
    public:
        static void Destroy(BGSTerrainChunk*& a_chunk);
    };
};
