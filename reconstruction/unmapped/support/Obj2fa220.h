// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Prefix2fa220, Secondary2fa220, Derived2fa220, Target2fa220, Obj2fa220, Obj2fa220::GetValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Prefix2fa220
{
    std::uint64_t unk00[2];  // 0x00
    void* m_value;           // 0x10
    std::uint64_t unk18;     // 0x18
};
static_assert(sizeof(Prefix2fa220) == 0x20, "Prefix2fa220 size");

struct Secondary2fa220
{
    std::uint64_t unk00;  // 0x00
};

struct Derived2fa220 : public Prefix2fa220, public Secondary2fa220
{
};

class Target2fa220
{
public:
    virtual ~Target2fa220();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual Secondary2fa220* GetSecondary() const;
};

class Obj2fa220
{
public:
    void* GetValue() const;

    std::uint64_t unk00[2];  // 0x00
    Target2fa220* m_target;  // 0x10
};
static_assert(offsetof(Obj2fa220, m_target) == 0x10, "m_target offset");
