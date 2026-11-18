// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xef71c0 NiStringExtraData::IsEqual
// 0xef70e0 NiStringExtraData::LoadBinary
// 0xef7130 NiStringExtraData::RegisterStreamables
#include "NiStringExtraData.h"

// TODO body: RVA 0xef71c0, 21 bytes, NiStringExtraData::IsEqual.
bool NiStringExtraData::IsEqual(NiObject* a_object)
{
    if (a_object != nullptr && value._data == static_cast<NiStringExtraData*>(a_object)->value._data) {
        return true;
    }
    return false;
}

// TODO body: RVA 0xef70e0, 43 bytes, NiStringExtraData::LoadBinary.
void NiStringExtraData::LoadBinary(NiStream& a_stream)
{
    NiExtraData::LoadBinary(a_stream);
    a_stream.LoadFixedString(value);
}

// TODO body: RVA 0xef7130, 62 bytes, NiStringExtraData::RegisterStreamables.
bool NiStringExtraData::RegisterStreamables(NiStream& a_stream)
{
    if (!NiExtraData::RegisterStreamables(a_stream)) {
        return false;
    }
    a_stream.RegisterFixedString(value);
    return true;
}
