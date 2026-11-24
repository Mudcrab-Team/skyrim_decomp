// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original declarations and the existing bounded leaf.
// Ownership and member names: GUESS(low)
// CommitTerrainDowngrade: GUESS(low); method name inferred from the body
#pragma once
#include <cstddef>
#include <cstdint>

struct QueuedLodTask;

// TerrainNode: GUESS(low); the pinned listing indexes a four-element array of
// these records with a 0x50-byte stride and passes each record's address to the
// node unload call. No field inside one record is read here, so each aligned
// eight-byte slot keeps a typed placeholder at its real offset.
struct TerrainNode
{
    std::uint64_t field00;
    std::uint64_t field08;
    std::uint64_t field10;
    std::uint64_t field18;
    std::uint64_t field20;
    std::uint64_t field28;
    std::uint64_t field30;
    std::uint64_t field38;
    std::uint64_t field40;
    std::uint64_t field48;
};
static_assert(sizeof(TerrainNode) == 0x50, "TerrainNode follows the observed index stride");

// QueuedLodOwner: GUESS(low); the owner record the commit reads: the committed
// task at +0x08, the node array at +0x30, and a state-flag word at +0x40.
struct QueuedLodOwner
{
    std::uint64_t field00;
    QueuedLodTask* currentTask;  // +0x08 replaced by the pending task
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    std::uint64_t unknown28;
    TerrainNode* nodes;  // +0x30 four records of 0x50 bytes
    std::uint64_t unknown38;
    std::uint32_t flags;  // +0x40 bits 1, 3 and 4 cleared, bit 2 set
};
static_assert(offsetof(QueuedLodOwner, currentTask) == 0x08, "currentTask follows the listing");
static_assert(offsetof(QueuedLodOwner, nodes) == 0x30, "nodes follows the listing");
static_assert(offsetof(QueuedLodOwner, flags) == 0x40, "flags follows the listing");

// QueuedLodTask, status: existing matched declarations.
// unknown28, Function5111e0: GUESS(low); the listing calls the object held at
// +0x28 before it commits the task.
struct QueuedLodTask
{
    std::uint32_t field00;
    std::uint32_t unknown04;
    std::uint32_t unknown08;
    std::uint32_t status;
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    void* unknown28;
};
static_assert(offsetof(QueuedLodTask, status) == 0x0C, "status follows the listing");
static_assert(offsetof(QueuedLodTask, unknown28) == 0x28, "unknown28 follows the listing");

void Function5111e0(void* a_object);
// Function514e00: GUESS(low); releases the task it replaced at owner + 0x08.
void Function514e00(QueuedLodTask* a_task);
// UnloadDataRecurse: GUESS(low); the pack associates the target with the terrain
// node unload. Declared only.
void UnloadDataRecurse(TerrainNode* a_node, std::uint32_t a_flags);

// Slot5: GUESS(low); method name inferred from vtable owner and slot
class BGSQueuedTerrainDowngrade
{
public:
    virtual std::uint32_t Slot5() const;

    bool Function51ac30() const;
    void Function51acf0();
    void CommitTerrainDowngrade();

    QueuedLodOwner* owner;
    std::uint8_t unknown10[4];
    bool cancelled;
    QueuedLodTask* task;

};

void ReleaseTerrainDowngradeTask(QueuedLodTask* a_task);
