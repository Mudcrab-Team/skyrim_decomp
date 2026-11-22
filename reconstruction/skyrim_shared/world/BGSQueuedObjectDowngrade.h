// Source exposure: mixed (pinned image listing and RTTI).
// Code origin: original declarations and the existing bounded leaf.
// Ownership and member names: GUESS(low)
#pragma once
#include <cstdint>
#include "BGSQueuedTerrainDowngrade.h"
// Slot5: GUESS(low); method name inferred from vtable owner and slot
class BGSQueuedObjectDowngrade
{
public:
    virtual std::uint32_t Slot5() const;

    bool Function51b2f0() const;
    void Function51b3b0();

    QueuedLodOwner* owner;
    std::uint8_t unknown10[4];
    bool cancelled;
    QueuedLodTask* task;

};

void ReleaseObjectDowngradeTask(QueuedLodTask* a_task);
