// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseComponent1f0a00, Unit1f0a00, CopyName1f0a00, Slot1, Slot2, Slot3, SetName, name: GUESS(low)
#pragma once

#include <cstddef>

class BaseComponent1f0a00
{
public:
    virtual ~BaseComponent1f0a00();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void SetName(const char* a_name);
};

class Unit1f0a00 : public BaseComponent1f0a00
{
public:
    void CopyName1f0a00(BaseComponent1f0a00* a_source);  // compared: 0x1f0a00

    const char* name;  // 08
};
static_assert(offsetof(Unit1f0a00, name) == 0x08, "Unit1f0a00::name offset");
