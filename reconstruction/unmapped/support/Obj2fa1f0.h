// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Inner2fa1f0, Prefix2fa1f0, Secondary2fa1f0, Target2fa1f0, Obj2fa1f0, Obj2fa1f0::GetValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Inner2fa1f0
{
    std::uint64_t unk00[2];  // 0x00
    void* m_value;           // 0x10
};

struct Prefix2fa1f0
{
    std::uint64_t unk00[4];  // 0x00
};
static_assert(sizeof(Prefix2fa1f0) == 0x20, "Prefix2fa1f0 size");

struct Secondary2fa1f0
{
    Inner2fa1f0* m_inner;  // 0x00
};

struct Target2fa1f0 : public Prefix2fa1f0, public Secondary2fa1f0
{
};

class Obj2fa1f0
{
public:
    void* GetValue() const;

    std::uint64_t unk00[2];  // 0x00
    Target2fa1f0* m_target;  // 0x10
};
static_assert(offsetof(Obj2fa1f0, m_target) == 0x10, "m_target offset");
