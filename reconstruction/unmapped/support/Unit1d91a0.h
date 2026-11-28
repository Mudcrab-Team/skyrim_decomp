// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseComponent1d91a0, SubIcon1d91a0, Unit1d91a0, Slot1, Clear, icon: GUESS(low)
#pragma once

class BaseComponent1d91a0
{
public:
    virtual ~BaseComponent1d91a0() {}
};

class SubIcon1d91a0
{
public:
    virtual ~SubIcon1d91a0();
    virtual void Slot1();
    virtual void Clear();
};

class Unit1d91a0 : public BaseComponent1d91a0
{
public:
    ~Unit1d91a0() override;  // compared: 0x1d91a0

    SubIcon1d91a0 icon;  // 08
};
