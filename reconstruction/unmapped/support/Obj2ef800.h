// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Entry2ef800, ExtraList2ef800, Obj2ef800, Obj2ef800::GetValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Entry2ef800
{
    std::uint64_t unk00[7];  // 0x00
    std::int32_t m_value;    // 0x38
};
static_assert(offsetof(Entry2ef800, m_value) == 0x38, "m_value offset");

class ExtraList2ef800
{
public:
    const Entry2ef800* FindEntry() const;
};

class Obj2ef800
{
public:
    std::int32_t GetValue() const;

    std::uint64_t unk00[14];    // 0x00
    ExtraList2ef800 m_extra;    // 0x70
};
static_assert(offsetof(Obj2ef800, m_extra) == 0x70, "m_extra offset");
