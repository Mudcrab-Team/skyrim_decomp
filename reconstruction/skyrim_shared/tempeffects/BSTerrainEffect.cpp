// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x4b7c40 BSTerrainEffect::GetManagerHandlesSaveLoad
#include "BSTerrainEffect.h"

// Reads the base class flag at 0x24 that the target loads; what the flag means is not verified here.
bool BSTerrainEffect::GetManagerHandlesSaveLoad() const
{
    return initialized;
}
