// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Character, Character::sub_1406783D0: CRASHLOGGER_PDB(59818@2026.10.24)
// BSHandleRefObject, HandleEntry, g_handleTable, Character::unk00, Character::unk1f0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct BSHandleRefObject
{
    std::uint8_t  unk00[0x8];
    std::uint32_t handleRefCount;  // 0x08
};

struct HandleEntry
{
    std::uint32_t      flags;  // 0x00
    std::uint32_t      unk04;  // 0x04
    BSHandleRefObject* ptr;    // 0x08
};
static_assert(sizeof(HandleEntry) == 0x10, "HandleEntry size");

extern HandleEntry g_handleTable[];

class Character
{
public:
    bool sub_1406783D0() const;

    std::uint8_t  unk00[0x1f0];
    std::uint32_t unk1f0;  // 0x1f0
};
static_assert(offsetof(Character, unk1f0) == 0x1f0, "Character::unk1f0 offset");
