// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x956d90 Leaf956d90::Invoke
// 0x951e80 MagicItemData::GetEnabled
#include "MagicItemData.h"

// ReadEnabledFlag: GUESS(low)
bool ReadEnabledFlag(void* a_data);

// RVA 0x956d90, 6 bytes, MagicItemData::GetCount.
std::uint32_t MagicItemData::GetCount()
{
    return 1;
}

// RVA 0x951e80, 9 bytes, MagicItemData::GetEnabled.
bool MagicItemData::GetEnabled()
{
    return ReadEnabledFlag(data18);
}
