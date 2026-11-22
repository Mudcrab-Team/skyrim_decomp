// Source exposure: mixed (pinned image listing and RTTI).
// Code origin: original declarations and the existing bounded leaf.
// Ownership and member names: GUESS(low)
#pragma once
#include <cstdint>

struct QueuedLodOwner;

struct QueuedLodTask {
    std::uint8_t unknown00[0xC];
    std::uint32_t status;
};
// Slot5: GUESS(low); method name inferred from vtable owner and slot
class BGSQueuedTerrainDowngrade
{
public:
    virtual std::uint32_t Slot5() const;

    bool Function51ac30() const;
    void Function51acf0();

    QueuedLodOwner* owner;
    std::uint8_t unknown10[4];
    bool cancelled;
    QueuedLodTask* task;

};

void ReleaseTerrainDowngradeTask(QueuedLodTask* a_task);
