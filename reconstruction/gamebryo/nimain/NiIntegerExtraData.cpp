// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xf121e0 NiIntegerExtraData::IsEqual
#include "NiIntegerExtraData.h"

// TODO body: RVA 0xf121e0, 19 bytes, NiIntegerExtraData::IsEqual.
bool NiIntegerExtraData::IsEqual(NiObject* a_object)
{
    if (a_object && value == static_cast<NiIntegerExtraData*>(a_object)->value) {
        return true;
    }
    return false;
}
