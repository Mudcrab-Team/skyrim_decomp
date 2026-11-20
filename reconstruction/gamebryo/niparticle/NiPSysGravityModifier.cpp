// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xf9c400 NiPSysGravityModifier::LinkObject
// 0xf9d760 NiPSysGravityModifier::~NiPSysGravityModifier
#include "NiPSysGravityModifier.h"

void NiPSysGravityModifier::LinkObject(NiStream& a_stream)
{
    NiPSysModifier::LinkObject(a_stream);
    field30 = a_stream.ReadLinkID();
}

// Not compared: its definition places the class vftable in this unit. The destructor is declared,
// not defined, as in the listing, which calls the complete destructor in a separate function
// (cookbook rule 14).
NiPSysGravityModifier::NiPSysGravityModifier()
{
}
