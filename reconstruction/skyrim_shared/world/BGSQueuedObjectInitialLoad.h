// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function51c550.
// BGSQueuedObjectInitialLoad: EXE_RTTI
// Slot5, Function51c550, ReleaseQueuedObject, unknown08, unknown10, target: GUESS(low)
#pragma once
#include <cstdint>

void ReleaseQueuedObject(void* a_target);

class BGSQueuedObjectInitialLoad
{
public:
    virtual std::uint32_t Slot5() const;
    void Function51c550();

    std::uint64_t unknown08;
    std::uint64_t unknown10;
    void* target;
};
