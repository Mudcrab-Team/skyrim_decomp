// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of point-radius accessors. Stamped as a twin of matched 0x449810 (skyrim/ai/BGSAIWorldLocationPointRadius): source copied, names replaced by placeholders.
// PointLocationVec3, PointLocationResult: GUESS(low)
// Functionb42a40, Ownerb42a40: GUESS(low) STANDIN
// Slot8, pos, pad14, member, fallbackSpace, field28, field2C, field30, field31, Function448e10, Function448e60, Function448e90, Function448ed0: GUESS(low) STANDIN
#pragma once
#include "BGSAIWorldLocationPointRadius.h"

class Ownerb42a40
{
public:
    virtual void* Slot8() const;
    float Function448e10() const;
    std::uint8_t Function448e60() const;
    bool Function448e90(PointLocationResult* a_out) const;
    std::uint8_t Function448ed0() const;
    float Functionb42a40() const;

    PointLocationVec3 pos;  // 08
    std::uint32_t pad14;  // 14
    void* member;  // 18
    void* fallbackSpace;  // 20
    float field28;  // 28
    float field2C;  // 2C
    std::uint8_t field30;  // 30
    std::uint8_t field31;  // 31
};

