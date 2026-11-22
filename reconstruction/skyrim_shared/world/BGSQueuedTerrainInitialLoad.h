// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function51c570.
// BGSQueuedTerrainInitialLoad: EXE_RTTI
// Slot5, Function51c570, ReleaseQueuedTerrain, unknown08, unknown10, target: GUESS(low)
#pragma once
#include <cstdint>

void ReleaseQueuedTerrain(void* a_target);

class BGSQueuedTerrainInitialLoad
{
public:
    virtual std::uint32_t Slot5() const;
    void Function51c570();

    std::uint64_t unknown08;
    std::uint64_t unknown10;
    void* target;
};
