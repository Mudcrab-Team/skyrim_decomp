// Code origin: original from the listing and community declarations, except TestBit, which is close to the sibling helper named below
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: TestBit is close to the sibling helper (tools/check_origin.py similarity 0.82).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// TestBit: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// 0x264510 TESObjectSTAT::IsHeadingMarker
// 0x2878f0 TESObjectSTAT::SetIsSkyObject
// 0x287910 TESObjectSTAT::QIsSkyObject
// TESObjectSTAT::QIsSkyObject: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// TESObjectSTAT::SetIsSkyObject: CRASHLOGGER_PDB(59818@2026.10.24)
#include "TESObjectSTAT.h"

void TESObjectSTAT::SetIsSkyObject(bool a_set)
{
    SetFormFlag(this, kIsSkyObject, a_set);
}

bool TESObjectSTAT::QIsSkyObject() const
{
    return (static_cast<std::uint8_t>(inGameFormFlags) >> 5) & 1u;
}

// TODO body: RVA 0x264510, 9 bytes, TESObjectSTAT::IsHeadingMarker.
bool TESObjectSTAT::IsHeadingMarker() const
{
    return TestBit(formFlags, 2);
}
