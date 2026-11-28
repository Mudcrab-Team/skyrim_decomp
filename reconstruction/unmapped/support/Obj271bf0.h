// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Base271bf0A, Base271bf0B, Obj271bf0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Base271bf0A
{
public:
    virtual ~Base271bf0A();

    std::uint8_t unk08[0x28];  // 0x08
};

class Base271bf0B
{
public:
    virtual ~Base271bf0B();
};

class Obj271bf0 : public Base271bf0A, public Base271bf0B
{
public:
    ~Obj271bf0() override;
};

static_assert(sizeof(Base271bf0A) == 0x30, "Base271bf0A size");
