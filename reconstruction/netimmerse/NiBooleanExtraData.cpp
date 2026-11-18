// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xf0ff60 NiBooleanExtraData::IsEqual
#include "NiBooleanExtraData.h"

// TODO body: RVA 0xf0ff60, 20 bytes, NiBooleanExtraData::IsEqual.
bool NiBooleanExtraData::IsEqual(NiObject* a_object)
{
    if (a_object != nullptr && value == static_cast<NiBooleanExtraData*>(a_object)->value) {
        return true;
    }
    return false;
}
