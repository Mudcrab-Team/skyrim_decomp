// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorThread, CombatBehaviorThread::Suspend: CRASHLOGGER_PDB(59818@2026.10.24)
// ChildThreadArray, CombatBehaviorThread::unk00, CombatBehaviorThread::flags, CombatBehaviorThread::unk154, CombatBehaviorThread::children: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class CombatBehaviorThread;

struct ChildThreadArray
{
    CombatBehaviorThread** Data()
    {
        return capacity < 0 ? local : heap;
    }

    std::int32_t capacity;  // 0x00
    std::uint32_t unk04;    // 0x04
    union
    {
        CombatBehaviorThread** heap;
        CombatBehaviorThread*  local[4];
    };                      // 0x08
    std::uint32_t size;     // 0x28
};
static_assert(offsetof(ChildThreadArray, heap) == 0x08, "ChildThreadArray::heap offset");
static_assert(offsetof(ChildThreadArray, size) == 0x28, "ChildThreadArray::size offset");

class CombatBehaviorThread
{
public:
    void Suspend();

    std::uint8_t     unk00[0x150];
    std::uint32_t    flags;      // 0x150
    std::uint8_t     unk154[0x14];
    ChildThreadArray children;   // 0x168
};
static_assert(offsetof(CombatBehaviorThread, flags) == 0x150, "CombatBehaviorThread::flags offset");
static_assert(offsetof(CombatBehaviorThread, children) == 0x168, "CombatBehaviorThread::children offset");
