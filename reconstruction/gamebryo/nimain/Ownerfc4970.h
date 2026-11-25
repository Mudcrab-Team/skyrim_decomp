// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xf1ede0 (gamebryo/nimain/NiAccumulator): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Ownerfc4970: GUESS(low) STANDIN
// unknown10, StartGroupingAlphas, StopGroupingAlphas, StartAccumulating: GUESS(low) STANDIN
#pragma once
#include "NiAccumulator.h"

class Ownerfc4970 : public NiObject
{
public:
    Ownerfc4970();
    virtual void FinishAccumulating();
    virtual void* StartGroupingAlphas(NiBound* a_bound);
    virtual void StopGroupingAlphas(void* a_group);
    virtual void StartAccumulating(NiCamera* a_camera);
    virtual ~Ownerfc4970();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint64_t unknown10;  // 10
};
static_assert(sizeof(Ownerfc4970) == 0x18, "Ownerfc4970 size");
