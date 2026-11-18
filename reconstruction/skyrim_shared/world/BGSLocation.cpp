// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x2984a0 BGSLocation::InitializeData
// 0x29cd00 BGSLocation::~BGSLocation
#include "BGSLocation.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the deleting destructor.
BGSLocation::BGSLocation()
{
}

void BGSLocation::InitializeData()
{
    parentLoc = nullptr;
    musicType = nullptr;
    unreportedCrimeFaction = nullptr;
    worldLocMarker = gNullHandle;
    horseLocMarker = gNullHandle;
    worldLocRadius = 0.0f;
    clearedFlags = 0;
    lastChecked = 0;
}
