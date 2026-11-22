// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of point-radius accessors.
// Adapted bodies: none.
// BGSAIWorldLocationPointRadius: EXE_RTTI
// Slot8, PointLocationVec3, PointLocationResult, pos, x, y, z, pad14, member, fallbackSpace, field28, field2C, field30, field31, Function448e10, Function448e60, Function448e90, Function448ed0, Function449810: GUESS(low)
#pragma once
#include <cstdint>

struct PointLocationVec3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct PointLocationResult
{
    PointLocationVec3 pos;  // 00
    std::uint32_t pad0C;  // 0C
    void* space;  // 10
};

class BGSAIWorldLocationPointRadius
{
public:
    virtual void* Slot8() const;
    float Function448e10() const;
    std::uint8_t Function448e60() const;
    bool Function448e90(PointLocationResult* a_out) const;
    std::uint8_t Function448ed0() const;
    float Function449810() const;

    PointLocationVec3 pos;  // 08
    std::uint32_t pad14;  // 14
    void* member;  // 18
    void* fallbackSpace;  // 20
    float field28;  // 28
    float field2C;  // 2C
    std::uint8_t field30;  // 30
    std::uint8_t field31;  // 31
};
