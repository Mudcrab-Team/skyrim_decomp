// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysTurbulenceFieldModifier, NiPSysTurbulenceFieldModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysFieldModifier, NiObject, frequency: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiObject
{
public:
    virtual ~NiObject();
};

class NiPSysFieldModifier : public NiObject
{
public:
    ~NiPSysFieldModifier() override;
    bool IsEqual(NiObject* a_other);

    std::uint8_t unk08[0x48];  // 08
};
static_assert(sizeof(NiPSysFieldModifier) == 0x50, "NiPSysFieldModifier size");

class NiPSysTurbulenceFieldModifier : public NiPSysFieldModifier
{
public:
    bool IsEqual(NiObject* a_other);  // compared: 0xfbb220

    float frequency;  // 50
};
static_assert(offsetof(NiPSysTurbulenceFieldModifier, frequency) == 0x50, "frequency offset");
