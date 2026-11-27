// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorThread, CombatBehaviorThread::SetAborted: CRASHLOGGER_PDB(59818@2026.10.24)
// ChildThreadArray, CombatBehaviorThread::unk00, CombatBehaviorThread::state, CombatBehaviorThread::unk14c, CombatBehaviorThread::children: GUESS(low)
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

    std::int32_t  capacity;  // 0x00
    std::uint32_t unk04;     // 0x04
    union
    {
        CombatBehaviorThread** heap;
        CombatBehaviorThread*  local[4];
    };                       // 0x08
    std::uint32_t size;      // 0x28
};
static_assert(offsetof(ChildThreadArray, heap) == 0x08, "ChildThreadArray::heap offset");
static_assert(offsetof(ChildThreadArray, size) == 0x28, "ChildThreadArray::size offset");

class CombatBehaviorThread
{
public:
    void SetAborted();

    std::uint8_t     unk00[0x148];
    std::uint32_t    state;      // 0x148
    std::uint8_t     unk14c[0x1c];
    ChildThreadArray children;   // 0x168
};
static_assert(offsetof(CombatBehaviorThread, state) == 0x148, "CombatBehaviorThread::state offset");
static_assert(offsetof(CombatBehaviorThread, children) == 0x168, "CombatBehaviorThread::children offset");
