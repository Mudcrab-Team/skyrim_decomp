// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xfdc610 (gamebryo/nimain/BSOcclusionShape): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner7c69b0: GUESS(low) STANDIN
// unknown10, CreateClone, GetRTTI: GUESS(low) STANDIN
#pragma once
#include "BSOcclusionShape.h"

class Owner7c69b0 : public NiObject
{
public:
    Owner7c69b0();
    virtual ~Owner7c69b0();
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);
    virtual const NiRTTI* GetRTTI() const;

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x38];  // 10
};
static_assert(sizeof(Owner7c69b0) == 0x48, "Owner7c69b0 size");
