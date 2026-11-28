// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysAirFieldModifier, NiPSysAirFieldModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysFieldModifier, NiObject, unk60, unk64, unk68: GUESS(low)
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

    std::uint8_t unk08[0x58];  // 08
};
static_assert(sizeof(NiPSysFieldModifier) == 0x60, "NiPSysFieldModifier size");

class NiPSysAirFieldModifier : public NiPSysFieldModifier
{
public:
    bool IsEqual(NiObject* a_other);  // compared: 0xfa4df0

    float unk60;  // 60
    float unk64;  // 64
    float unk68;  // 68
};
static_assert(offsetof(NiPSysAirFieldModifier, unk60) == 0x60, "unk60 offset");
static_assert(offsetof(NiPSysAirFieldModifier, unk64) == 0x64, "unk64 offset");
static_assert(offsetof(NiPSysAirFieldModifier, unk68) == 0x68, "unk68 offset");
