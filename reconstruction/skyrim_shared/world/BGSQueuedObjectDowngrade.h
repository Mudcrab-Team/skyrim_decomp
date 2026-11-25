// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned listing and labelled declarations.
// Slot5, Function51b320, CommitQueuedLodTask, UnloadTerrainNodeData, QueuedLodNode,
// QueuedLodObjectOwner and its members, pendingTask, nodes, flags: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>
#include "BGSQueuedTerrainDowngrade.h"

// One entry of QueuedLodObjectOwner::nodes. This unit observes only the 0x50-byte stride and passes
// each entry's address to the unload routine, so the entry contents stay labelled unknowns.
struct QueuedLodNode
{
    std::uint64_t field00;
    std::uint64_t unknown08;
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    std::uint64_t unknown28;
    std::uint64_t unknown30;
    std::uint64_t unknown38;
    std::uint64_t unknown40;
    std::uint64_t unknown48;
};

// QueuedLodObjectOwner: GUESS(low); the owner record the object commit path reads. It is a separate
// type from the QueuedLodOwner of BGSQueuedTerrainDowngrade.h because the task slot sits at 0x10
// here and at 0x08 there.
struct QueuedLodObjectOwner
{
    std::uint64_t field00;
    std::uint64_t unknown08;
    QueuedLodTask* pendingTask;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    std::uint64_t unknown28;
    QueuedLodNode* nodes;
    std::uint64_t unknown38;
    std::uint32_t flags;
};

static_assert(sizeof(QueuedLodNode) == 0x50, "queued lod node stride");
static_assert(offsetof(QueuedLodObjectOwner, pendingTask) == 0x10, "owner pending task offset");
static_assert(offsetof(QueuedLodObjectOwner, nodes) == 0x30, "owner node table offset");
static_assert(offsetof(QueuedLodObjectOwner, flags) == 0x40, "owner flags offset");

// Slot5: GUESS(low); method name inferred from vtable owner and slot
class BGSQueuedObjectDowngrade
{
public:
    virtual std::uint32_t Slot5() const;

    bool Function51b2f0() const;
    void Function51b3b0();
    void Function51b320();

    QueuedLodObjectOwner* owner;
    std::uint8_t unknown10[4];
    bool cancelled;
    QueuedLodTask* task;

};

void ReleaseObjectDowngradeTask(QueuedLodTask* a_task);
void CommitQueuedLodTask(void* a_payload);
void UnloadTerrainNodeData(QueuedLodNode* a_node, std::uint32_t a_mode);
