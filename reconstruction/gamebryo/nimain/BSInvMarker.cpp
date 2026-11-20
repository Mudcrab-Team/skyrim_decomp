// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xfff1d0 BSInvMarker::~BSInvMarker
// 0xffed30 BSInvMarker::CreateClone
// 0xfff210 BSInvMarker::GetRTTI
#include "BSInvMarker.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSInvMarker::BSInvMarker()
{
}


NiObject* BSInvMarker::CreateClone(NiCloningProcess&)
{
    return this;
}

const NiRTTI* BSInvMarker::GetRTTI() const
{
    return &NiRTTI_BSInvMarker;
}
