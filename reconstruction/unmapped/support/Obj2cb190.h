// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// LoadedData2cb190, WorldSpace2cb190, Obj2cb190, Obj2cb190::Function2cb190: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LoadedData2cb190
{
    std::uint8_t unk00[0xD0];  // 0x00
    std::uint8_t fieldD0;      // 0xD0
};

struct WorldSpace2cb190
{
    std::uint8_t unk00[0x140];  // 0x000
    void* field140;             // 0x140
};

class Obj2cb190
{
public:
    void* Function2cb190() const;

    std::uint8_t unk00[0x40];       // 0x000
    std::uint8_t cellFlags;         // 0x040
    std::uint8_t unk41[0xE7];       // 0x041
    WorldSpace2cb190* worldSpace;   // 0x128
    LoadedData2cb190* loadedData;   // 0x130
};

static_assert(offsetof(LoadedData2cb190, fieldD0) == 0xD0, "fieldD0 offset");
static_assert(offsetof(WorldSpace2cb190, field140) == 0x140, "field140 offset");
static_assert(offsetof(Obj2cb190, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2cb190, worldSpace) == 0x128, "worldSpace offset");
static_assert(offsetof(Obj2cb190, loadedData) == 0x130, "loadedData offset");
