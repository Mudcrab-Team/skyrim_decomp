// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xfff1d0 (gamebryo/nimain/BSInvMarker): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner147c60: GUESS(low) STANDIN
// unknown18: GUESS(low) STANDIN
#pragma once
#include "BSInvMarker.h"

class Owner147c60 : public NiExtraData
{
public:
    Owner147c60();
    virtual ~Owner147c60() {}
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);
    virtual const NiRTTI* GetRTTI() const;

    std::uint8_t unknown18[0x10];  // 18
};
static_assert(sizeof(Owner147c60) == 0x28, "Owner147c60 size");
