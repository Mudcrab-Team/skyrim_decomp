// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Entry2ef7a0, ExtraList2ef7a0, Obj2ef7a0, Obj2ef7a0::GetValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Entry2ef7a0
{
    std::uint64_t unk00[2];  // 0x00
    std::uint32_t unk10;     // 0x10
    std::int32_t m_value;    // 0x14
};
static_assert(offsetof(Entry2ef7a0, m_value) == 0x14, "m_value offset");

class ExtraList2ef7a0
{
public:
    const Entry2ef7a0* FindEntry() const;
};

class Obj2ef7a0
{
public:
    std::int32_t GetValue() const;

    std::uint64_t unk00[14];    // 0x00
    ExtraList2ef7a0 m_extra;    // 0x70
};
static_assert(offsetof(Obj2ef7a0, m_extra) == 0x70, "m_extra offset");
