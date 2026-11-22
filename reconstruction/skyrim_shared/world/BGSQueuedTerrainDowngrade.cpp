// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BGSQueuedTerrainDowngrade: EXE_RTTI
// Slot5, owner, task, cancelled and release function names: GUESS(low)
// 0x51c740 BGSQueuedTerrainDowngrade::Slot5
// 0x51ac30 BGSQueuedTerrainDowngrade::Function51ac30
// 0x51acf0 BGSQueuedTerrainDowngrade::Function51acf0
#include "BGSQueuedTerrainDowngrade.h"
// Slot5: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t BGSQueuedTerrainDowngrade::Slot5() const
{
    return 0x1;
}

namespace {
constexpr std::uint32_t kStatusMask = 0x70000000u;
constexpr std::uint32_t kFirstDowngradeState = 0x30000000u;
constexpr std::uint32_t kSecondDowngradeState = 0x40000000u;
}

// Test whether the pending task is in either of the two downgrade states.
bool BGSQueuedTerrainDowngrade::Function51ac30() const
{
    if (task) {
        const std::uint32_t status = task->status & kStatusMask;
        return status == kFirstDowngradeState || status == kSecondDowngradeState;
    }
    return false;
}

// Drop the pending task and mark this request as cancelled.
void BGSQueuedTerrainDowngrade::Function51acf0()
{
    QueuedLodTask* pending = task;
    if (pending) {
        task = nullptr;
        ReleaseTerrainDowngradeTask(pending);
    }
    cancelled = true;
}
