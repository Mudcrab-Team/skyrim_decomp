// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorThread, CombatBehaviorThread::CheckParent: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatBehaviorThread::unk00, CombatBehaviorThread::parent: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class CombatBehaviorThread
{
public:
    bool CheckParent(const CombatBehaviorThread* a_parent) const;

    std::uint8_t          unk00[0x160];
    CombatBehaviorThread* parent;  // 0x160
};
static_assert(offsetof(CombatBehaviorThread, parent) == 0x160, "CombatBehaviorThread::parent offset");
