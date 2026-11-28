// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// UnregisterFactory2dd380, Obj2dd380Base, Obj2dd380: GUESS(low)
#pragma once

#include <cstdint>

void UnregisterFactory2dd380(std::uint8_t a_formType);

class Obj2dd380Base
{
public:
    virtual ~Obj2dd380Base() {}
};

class Obj2dd380 : public Obj2dd380Base
{
public:
    Obj2dd380();

    ~Obj2dd380() override
    {
        UnregisterFactory2dd380(0x3D);
    }
};
static_assert(sizeof(Obj2dd380) == 0x8, "Obj2dd380 size");
