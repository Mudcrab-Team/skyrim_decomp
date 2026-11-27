// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original declarations and the existing bounded leaf.
// Adapted bodies: none
// SPDX-License-Identifier: CC0-1.0
// BGSQueuedTerrainDowngrade: EXE_RTTI
// Slot5, owner, task, cancelled and release function names: GUESS(low)
// 0x51c740 BGSQueuedTerrainDowngrade::Slot5
// 0x51ac30 BGSQueuedTerrainDowngrade::Function51ac30
// 0x51acf0 BGSQueuedTerrainDowngrade::Function51acf0
// 0x51ac60 BGSQueuedTerrainDowngrade::CommitTerrainDowngrade
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
constexpr std::uint32_t kClearMask = ~0x1Au;
constexpr std::uint32_t kDowngradingFlag = 0x4u;
constexpr std::uint32_t kTerrainNodeCount = 4;
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

// Make the pending task the owner's committed task, then unload the terrain
// nodes the owner still holds.
void BGSQueuedTerrainDowngrade::CommitTerrainDowngrade()
{
    Function5111e0(task->unknown28);

    QueuedLodTask* pending = task;
    QueuedLodTask* previous = owner->currentTask;
    if (pending != previous) {
        task = nullptr;
        owner->currentTask = pending;
        Function514e00(previous);
    }

    QueuedLodOwner* const record = owner;
    record->flags &= kClearMask;
    record->flags |= kDowngradingFlag;

    for (std::uint32_t i = 0; i < kTerrainNodeCount; ++i) {
        TerrainNode* node = owner->nodes ? &owner->nodes[i] : nullptr;
        UnloadDataRecurse(node, 1u);
    }
}
