// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESObjectCELL, TESWorldSpace, formFlags, cellFlags, worldSpace, GetCantWaitHere: CRASHLOGGER_PDB(59818@2026.10.24)
// DisallowsWaiting, unknown000, unknown014, unknown042: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class TESWorldSpace
{
public:
    bool DisallowsWaiting() const;
};

class TESObjectCELL
{
public:
    bool GetCantWaitHere() const;

    std::uint8_t   unknown000[0x10];   // 000
    std::uint32_t  formFlags;          // 010
    std::uint8_t   unknown014[0x2C];   // 014
    std::uint16_t  cellFlags;          // 040
    std::uint8_t   unknown042[0xE6];   // 042
    TESWorldSpace* worldSpace;         // 128
};
static_assert(offsetof(TESObjectCELL, formFlags) == 0x10, "formFlags offset");
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL, worldSpace) == 0x128, "worldSpace offset");
