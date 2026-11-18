// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xf9c400 NiPSysGravityModifier::LinkObject
#include "NiPSysGravityModifier.h"

void NiPSysGravityModifier::LinkObject(NiStream& a_stream)
{
    NiPSysModifier::LinkObject(a_stream);
    field30 = a_stream.ReadLinkID();
}
