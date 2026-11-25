// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:46
// BGSBtrDB, BGSBtrDB::DBTraits::ArgsType::operator=: SIBLING(fo4-private@1b765c70, author-permission)
// BGSBtrDB::DBTraits, BGSBtrDB::DBTraits::ArgsType, BGSBtrDB::DBTraits::ArgsType::pNode, BGSBtrDB::DBTraits::ArgsType::iCellX, BGSBtrDB::DBTraits::ArgsType::iCellY, BGSBtrDB::DBTraits::ArgsType::Diffuse, BGSBtrDB::DBTraits::ArgsType::Normal, BSTextureDBHandle, BSTextureDBHandle::pEntry, BSTextureDBHandle::Release, BSTerrainNode: GUESS(medium); names from the sibling body, declared outside the permitted folders, layout read from the listing
// unknown00, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSTextureDBHandle
{
    static void Release(void* a_old);

    void* pEntry;  // 00
};

class BSTerrainNode;

class BGSBtrDB
{
public:
    class DBTraits
    {
    public:
        class ArgsType
        {
        public:
            const ArgsType& operator=(const ArgsType& a_rhs);

            BSTerrainNode* pNode;       // 00
            std::int32_t iCellX;        // 08
            std::int32_t iCellY;        // 0C
            BSTextureDBHandle Diffuse;  // 10
            BSTextureDBHandle Normal;   // 18
        };
    };
};
