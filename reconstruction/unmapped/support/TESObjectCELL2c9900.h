// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESObjectCELL2c9900, DecQueuedDistantRefCount, TESObjectCELL2c9900::DecQueuedDistantRefCount: CRASHLOGGER_PDB(59818@2026.10.24)
// Ref2c9900, WorldSpace2c9900, RuntimeData2c9900: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class TESObjectCELL2c9900;

extern float g_unloadDelaySec2c9900;
extern std::uint32_t g_currentTimeMs2c9900;

struct Ref2c9900
{
    std::uint8_t unk00[0x54];  // 0x00
    float pos54[3];            // 0x54
};

struct WorldSpace2c9900
{
    TESObjectCELL2c9900* GetCellAt(const float* a_pos);
};

struct RuntimeData2c9900
{
    std::uint8_t unk00[0x174];   // 0x000
    long queuedRefCount;         // 0x174
    std::uint32_t expireTimeMs;  // 0x178
};

class TESObjectCELL2c9900
{
public:
    void DecQueuedDistantRefCount(const Ref2c9900* a_ref);

    std::uint8_t unk00[0x10];       // 0x000
    std::uint32_t formFlags;        // 0x010
    std::uint8_t unk14[0x2C];       // 0x014
    std::uint16_t cellFlags;        // 0x040
    std::uint8_t unk42[0x02];       // 0x042
    std::uint8_t cellState;         // 0x044
    std::uint8_t unk45[0xE3];       // 0x045
    WorldSpace2c9900* worldSpace;   // 0x128
    RuntimeData2c9900* runtimeData; // 0x130
};

static_assert(offsetof(Ref2c9900, pos54) == 0x54, "pos54 offset");
static_assert(offsetof(RuntimeData2c9900, queuedRefCount) == 0x174, "queuedRefCount offset");
static_assert(offsetof(RuntimeData2c9900, expireTimeMs) == 0x178, "expireTimeMs offset");
static_assert(offsetof(TESObjectCELL2c9900, formFlags) == 0x10, "formFlags offset");
static_assert(offsetof(TESObjectCELL2c9900, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL2c9900, cellState) == 0x44, "cellState offset");
static_assert(offsetof(TESObjectCELL2c9900, worldSpace) == 0x128, "worldSpace offset");
static_assert(offsetof(TESObjectCELL2c9900, runtimeData) == 0x130, "runtimeData offset");
