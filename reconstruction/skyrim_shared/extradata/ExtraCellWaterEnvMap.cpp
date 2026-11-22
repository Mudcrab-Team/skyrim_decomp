// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; GetType from a community public name, the other body from the pinned image listing.
// 0x18c1d0 ExtraCellWaterEnvMap::Function18c1d0
// Adapted bodies: none
// ExtraCellWaterEnvMap: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "ExtraCellWaterEnvMap.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraCellWaterEnvMap::GetType() const
{
    return 0xa6;
}

// Function18c1d0Target, Function18c1d0Target_Forward: GUESS(low); external helper reached by the tail jump.
class Function18c1d0Target;
void Function18c1d0Target_Forward(Function18c1d0Target* a_self, Function18c1d0Target* a_other);

void ExtraCellWaterEnvMap::Function18c1d0(ExtraCellWaterEnvMap* a_other)
{
    auto* other = reinterpret_cast<Function18c1d0Target*>(reinterpret_cast<char*>(a_other) + 0x10);
    auto* self  = reinterpret_cast<Function18c1d0Target*>(reinterpret_cast<char*>(this) + 0x10);
    return Function18c1d0Target_Forward(self, other);
}
