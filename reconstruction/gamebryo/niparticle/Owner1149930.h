// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xffe8e0 (gamebryo/niparticle/BSProceduralLightningTasklet): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner1149930: GUESS(low) STANDIN
// BSWin32TaskletData, unknown28, field_ac, unknownAD: GUESS(low) STANDIN
#pragma once
#include "BSProceduralLightningTasklet.h"

class Owner1149930 : public BSWin32TaskletData
{
public:
    virtual void OnComplete();

    std::uint8_t unknown28[0xe0];  // 28
    bool field_ac;  // AC
    std::uint8_t unknownAD[0x3];  // AD
};
static_assert(sizeof(Owner1149930) == 0x110, "Owner1149930 size");
