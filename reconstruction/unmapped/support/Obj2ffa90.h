// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// ExtraList2ffa90, BaseForm2ffa90, gSentinel2ffa90, Obj2ffa90, Obj2ffa90::GetValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class ExtraList2ffa90
{
public:
    float GetFloat() const;
};

class BaseForm2ffa90
{
public:
    std::uint16_t GetDefaultValue(const ExtraList2ffa90* a_extra) const;
};

extern const float gSentinel2ffa90;

class Obj2ffa90
{
public:
    float GetValue() const;

    std::uint64_t unk00[8];      // 0x00
    BaseForm2ffa90* m_base;      // 0x40
    std::uint64_t unk48[5];      // 0x48
    ExtraList2ffa90 m_extra;     // 0x70
};
static_assert(offsetof(Obj2ffa90, m_base) == 0x40, "m_base offset");
static_assert(offsetof(Obj2ffa90, m_extra) == 0x70, "m_extra offset");
