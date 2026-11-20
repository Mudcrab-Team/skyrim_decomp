// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1565d0 BSExtraData::IsNotEqual
// 0x156400 BSExtraData::~BSExtraData
#include "BSExtraData.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSExtraData::BSExtraData()
{
}

// Body done: RVA 0x1565d0, 3 bytes, BSExtraData::IsNotEqual.
bool BSExtraData::IsNotEqual(const BSExtraData* a_rhs) const
{
    return false;
}

