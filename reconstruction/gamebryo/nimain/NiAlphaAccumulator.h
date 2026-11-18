// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiAlphaAccumulator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// NiAccumulator, NiBackToFrontAccumulator: STANDIN EXE_RTTI
// NiAlphaAccumulator::IsEqual, NiAlphaAccumulator::~NiAlphaAccumulator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiBackToFrontAccumulator::IsEqual: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ~NiBackToFrontAccumulator: GUESS(low)
// unknown10, unknown18: GUESS(low)
#pragma once

#include <cstdint>
#include "../../netimmerse/NiObject.h"

class NiAccumulator : public NiObject
{
public:
    std::uint8_t unknown10[0x8];  // 10
};
static_assert(sizeof(NiAccumulator) == 0x18, "NiAccumulator size");

class NiBackToFrontAccumulator : public NiAccumulator
{
public:
    bool IsEqual(NiObject* a_object) override;
    ~NiBackToFrontAccumulator() override;
};

class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
public:
    NiAlphaAccumulator();
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xf0f290
    virtual ~NiAlphaAccumulator();  // compared: 0xf0f4a0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown18[0x40];  // 18
};
static_assert(sizeof(NiAlphaAccumulator) == 0x58, "NiAlphaAccumulator size");
