// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function51c550.
// Adapted bodies: none
// 0x51c720 BGSQueuedObjectInitialLoad::Slot5
// 0x51c550 BGSQueuedObjectInitialLoad::Function51c550
#include "BGSQueuedObjectInitialLoad.h"

std::uint32_t BGSQueuedObjectInitialLoad::Slot5() const
{
    return 0x5;
}

void BGSQueuedObjectInitialLoad::Function51c550()
{
    if (void* prev = target) {
        target = nullptr;
        ReleaseQueuedObject(prev);
    }
}
