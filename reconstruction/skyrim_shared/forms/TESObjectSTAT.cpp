// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x264510 TESObjectSTAT::IsHeadingMarker
// 0x2878f0 TESObjectSTAT::SetIsSkyObject
// TESObjectSTAT::SetIsSkyObject: CRASHLOGGER_PDB(59818@2026.10.24)
#include "TESObjectSTAT.h"

void TESObjectSTAT::SetIsSkyObject(bool a_set)
{
    SetFormFlag(this, kIsSkyObject, a_set);
}

// TODO body: RVA 0x264510, 9 bytes, TESObjectSTAT::IsHeadingMarker.
bool TESObjectSTAT::IsHeadingMarker() const
{
    return TestBit(formFlags, 2);
}
