// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BGSQueuedObjectDowngrade: EXE_RTTI
// Slot5, Function51b320, CommitQueuedLodTask, UnloadTerrainNodeData: GUESS(low)
// 0x51c710 BGSQueuedObjectDowngrade::Slot5
// 0x51b2f0 BGSQueuedObjectDowngrade::Function51b2f0
// 0x51b3b0 BGSQueuedObjectDowngrade::Function51b3b0
// 0x51b320 BGSQueuedObjectDowngrade::Function51b320
#include "BGSQueuedObjectDowngrade.h"
// Slot5: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t BGSQueuedObjectDowngrade::Slot5() const
{
    return 0x4;
}

namespace {
constexpr std::uint32_t kStatusMask = 0x70000000u;
constexpr std::uint32_t kFirstDowngradeState = 0x30000000u;
constexpr std::uint32_t kSecondDowngradeState = 0x40000000u;
constexpr std::uint32_t kOwnerFlagsClearMask = 0x160u;
constexpr std::uint32_t kOwnerFlagsSetMask = 0x80u;
constexpr std::uint32_t kNodeCount = 4;
constexpr std::uint32_t kUnloadMode = 2;
}

// Test whether the pending task is in either of the two downgrade states.
bool BGSQueuedObjectDowngrade::Function51b2f0() const
{
    if (task) {
        const std::uint32_t status = task->status & kStatusMask;
        return status == kFirstDowngradeState || status == kSecondDowngradeState;
    }
    return false;
}

// Drop the pending task and mark this request as cancelled.
void BGSQueuedObjectDowngrade::Function51b3b0()
{
    QueuedLodTask* pending = task;
    if (pending) {
        task = nullptr;
        ReleaseObjectDowngradeTask(pending);
    }
    cancelled = true;
}

// Hand the queued task to the owner, refresh the owner state and unload its terrain nodes.
void BGSQueuedObjectDowngrade::Function51b320()
{
    CommitQueuedLodTask(task->unknown28);
    QueuedLodTask* const pending = task;
    QueuedLodTask* const previous = owner->pendingTask;
    if (pending != previous) {
        task = nullptr;
        owner->pendingTask = pending;
        ReleaseObjectDowngradeTask(previous);
    }
    owner->flags = (owner->flags & ~kOwnerFlagsClearMask) | kOwnerFlagsSetMask;
    for (std::uint32_t i = 0; i < kNodeCount; ++i) {
        UnloadTerrainNodeData(owner->nodes ? &owner->nodes[i] : nullptr, kUnloadMode);
    }
}
