// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:83
// BGSTerrainChunk, BGSTerrainChunk::OnLoadFinished: SIBLING(fo4-private@1b765c70, author-permission)
// BGSTerrainNode::pManager, BGSTerrainManager::SetNeedsImmediateUpdate: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the same names stand in the sibling body
// BGSTerrainChunk::pNode, BGSTerrainChunk::bDoneLoading, BGSTerrainNode, BGSTerrainNode::sBaseCellX, BGSTerrainNode::sBaseCellY, BGSTerrainManager: GUESS(medium); names from the sibling body, declared outside the permitted folders, layout read from the listing
// unknown08, unknown21, unknown28, unknown4c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSTerrainManager
{
public:
    void SetNeedsImmediateUpdate(const int& a_cellX, const int& a_cellY);
};

class BGSTerrainNode
{
public:
    BGSTerrainManager* pManager;    // 00
    std::uint8_t unknown08[0x40];   // 08
    std::int16_t sBaseCellX;        // 48
    std::int16_t sBaseCellY;        // 4A
};

class BGSTerrainChunk
{
public:
    void OnLoadFinished();

    BGSTerrainNode* pNode;        // 00
    std::uint8_t unknown08[0x18]; // 08
    std::uint8_t bDoneLoading;    // 20
    std::uint8_t unknown21[7];    // 21
};
static_assert(sizeof(BGSTerrainChunk) == 0x28, "BGSTerrainChunk size");
