// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function51c570.
// Adapted bodies: none
// 0x51c750 BGSQueuedTerrainInitialLoad::Slot5
// 0x51c570 BGSQueuedTerrainInitialLoad::Function51c570
#include "BGSQueuedTerrainInitialLoad.h"

std::uint32_t BGSQueuedTerrainInitialLoad::Slot5() const
{
    return 0x2;
}

void BGSQueuedTerrainInitialLoad::Function51c570()
{
    if (void* prev = target) {
        target = nullptr;
        ReleaseQueuedTerrain(prev);
    }
}
