// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xfff1d0 (gamebryo/nimain/BSInvMarker): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner665230: GUESS(low) STANDIN
// unknown18: GUESS(low) STANDIN
#pragma once
#include "BSInvMarker.h"

class Owner665230 : public NiExtraData
{
public:
    Owner665230();
    virtual ~Owner665230() {}
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);
    virtual const NiRTTI* GetRTTI() const;

    std::uint8_t unknown18[0x10];  // 18
};
static_assert(sizeof(Owner665230) == 0x28, "Owner665230 size");
