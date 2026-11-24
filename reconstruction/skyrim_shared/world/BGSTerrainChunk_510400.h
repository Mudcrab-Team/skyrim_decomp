// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainChunk.cpp:69
// BGSBtrDB, BGSBtrDB::DBTraits::ArgsType::WaitForTextures: SIBLING(fo4-private@1b765c70, author-permission)
// BSTextureDB, BSTextureDB::WaitFor, BGSBtrDB::DBTraits,BGSBtrDB::DBTraits::ArgsType, BGSBtrDB::DBTraits::ArgsType::Diffuse, BGSBtrDB::DBTraits::ArgsType::Normal, BGSTerrainChunk, BGSTerrainChunk::NoiseTextureHandle, BSTextureDBHandle, BSTextureDBHandle::pEntry: GUESS(medium); names from the sibling body, declared outside the permitted folders, layout read from the listing
// unknown00, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSTextureDBHandle
{
    void* pEntry;  // 00
};

class BSTextureDB
{
public:
    static void WaitFor(const BSTextureDBHandle& a_handle, bool a_wait);
};

class BGSTerrainChunk
{
public:
    static BSTextureDBHandle NoiseTextureHandle;
};

class BGSBtrDB
{
public:
    class DBTraits
    {
    public:
        class ArgsType
        {
        public:
            void WaitForTextures() const;

            std::uint8_t unknown00[0x10];  // 00
            BSTextureDBHandle Diffuse;     // 10
            BSTextureDBHandle Normal;      // 18
        };
    };
};
