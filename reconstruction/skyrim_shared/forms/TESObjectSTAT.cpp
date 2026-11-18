// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x264510 TESObjectSTAT::IsHeadingMarker
#include "TESObjectSTAT.h"

// TODO body: RVA 0x264510, 9 bytes, TESObjectSTAT::IsHeadingMarker.
bool TESObjectSTAT::IsHeadingMarker() const
{
    return TestBit(formFlags, 2);
}
