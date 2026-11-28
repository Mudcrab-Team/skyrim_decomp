// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseObject1df140, DerivedObject1df140, Unit1df140, QueryValue1df140, Slot1, Slot2, Slot3, GetWordValue: GUESS(low)
#pragma once

#include <cstdint>

class BaseObject1df140
{
public:
    virtual ~BaseObject1df140();
};

class DerivedObject1df140 : public BaseObject1df140
{
public:
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual std::uint16_t GetWordValue();
};

struct Unit1df140
{
    static std::uint16_t QueryValue1df140(BaseObject1df140* a_object);  // compared: 0x1df140
};
