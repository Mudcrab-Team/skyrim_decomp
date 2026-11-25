// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x951e80 (skyrim_shared/magic/MagicItemData): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Ownercc0360, ReadEnabledFlag_cc0360: GUESS(low) STANDIN
// unknown08, data18: GUESS(low) STANDIN
#pragma once
#include "MagicItemData.h"

class Ownercc0360
{
public:
    virtual std::uint32_t GetCount();
    virtual bool GetEnabled();

    // Padding up to the pointer read by GetEnabled at offset 0x18.
    std::uint8_t unknown08[0x10];  // 08
    void* data18;  // 18
};
static_assert(sizeof(Ownercc0360) == 0x20, "Ownercc0360 size");
