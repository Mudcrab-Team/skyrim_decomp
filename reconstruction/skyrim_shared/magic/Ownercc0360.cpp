// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// Code origin: Stamped as a twin of matched 0x951e80 (skyrim_shared/magic/MagicItemData): source copied, names replaced by placeholders.
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0xcc0360 Ownercc0360::GetEnabled
#include "Ownercc0360.h"

// ReadEnabledFlag_cc0360: GUESS(low) STANDIN
bool ReadEnabledFlag_cc0360(void* a_data);

bool Ownercc0360::GetEnabled()
{
    return ReadEnabledFlag_cc0360(data18);
}
