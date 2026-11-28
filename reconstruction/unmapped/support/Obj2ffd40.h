// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// ExtraList2ffd40, gMin2ffd40, Obj2ffd40, Obj2ffd40::GetClampedValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class ExtraList2ffd40
{
public:
    float GetFloat() const;
};

extern const float gMin2ffd40;

class Obj2ffd40
{
public:
    float GetClampedValue() const;

    std::uint64_t unk00[14];    // 0x00
    ExtraList2ffd40 m_extra;    // 0x70
};
static_assert(offsetof(Obj2ffd40, m_extra) == 0x70, "m_extra offset");
