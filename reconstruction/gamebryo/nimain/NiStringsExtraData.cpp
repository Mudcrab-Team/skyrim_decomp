// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xeeeec0 NiStringsExtraData::GetRTTI
#include "NiStringsExtraData.h"

// GetRTTI: the RTTI object address is a constant in the listing.
const NiRTTI* NiStringsExtraData::GetRTTI() const
{
    return &NiRTTI_NiStringsExtraData;
}
