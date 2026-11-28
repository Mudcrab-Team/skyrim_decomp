// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// LoadedData2cb160, WorldSpace2cb160, Obj2cb160, Obj2cb160::Function2cb160: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LoadedData2cb160
{
    std::uint8_t unk00[0xB0];  // 0x00
    std::uint8_t fieldB0;      // 0xB0
};

struct WorldSpace2cb160
{
    std::uint8_t unk00[0x138];  // 0x000
    void* field138;             // 0x138
};

class Obj2cb160
{
public:
    void* Function2cb160() const;

    std::uint8_t unk00[0x40];       // 0x000
    std::uint8_t cellFlags;         // 0x040
    std::uint8_t unk41[0xE7];       // 0x041
    WorldSpace2cb160* worldSpace;   // 0x128
    LoadedData2cb160* loadedData;   // 0x130
};

static_assert(offsetof(LoadedData2cb160, fieldB0) == 0xB0, "fieldB0 offset");
static_assert(offsetof(WorldSpace2cb160, field138) == 0x138, "field138 offset");
static_assert(offsetof(Obj2cb160, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2cb160, worldSpace) == 0x128, "worldSpace offset");
static_assert(offsetof(Obj2cb160, loadedData) == 0x130, "loadedData offset");
