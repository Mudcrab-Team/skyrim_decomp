// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Base2724b0A, Base2724b0B, Obj2724b0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Base2724b0A
{
public:
    virtual ~Base2724b0A();

    std::uint8_t unk08[0x28];  // 0x08
};

class Base2724b0B
{
public:
    virtual ~Base2724b0B();
};

class Obj2724b0 : public Base2724b0A, public Base2724b0B
{
public:
    ~Obj2724b0() override;

    void Cleanup();
};

static_assert(sizeof(Base2724b0A) == 0x30, "Base2724b0A size");
