// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Base317180, Derived317180, Holder317180, Obj317180, Obj317180::GetDerived: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Base317180
{
public:
    virtual ~Base317180();
};

class Derived317180 : public Base317180
{
public:
    ~Derived317180() override;
};

class Holder317180
{
public:
    Base317180* GetObject() const;
};

class Obj317180
{
public:
    Derived317180* GetDerived() const;

    std::uint64_t unk00[8];  // 0x00
    Holder317180* m_holder;  // 0x40
};
static_assert(offsetof(Obj317180, m_holder) == 0x40, "m_holder offset");
