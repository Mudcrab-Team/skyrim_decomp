// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysDragFieldModifier, NiPSysDragFieldModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysFieldModifier, NiObject, useDirection, directionX, directionY, directionZ: GUESS(low)
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

class NiPSysDragFieldModifier : public NiPSysFieldModifier
{
public:
    bool IsEqual(NiObject* a_other);  // compared: 0xfab960

    bool useDirection;  // 50
    float directionX;  // 54
    float directionY;  // 58
    float directionZ;  // 5C
};
static_assert(offsetof(NiPSysDragFieldModifier, useDirection) == 0x50, "useDirection offset");
static_assert(offsetof(NiPSysDragFieldModifier, directionX) == 0x54, "directionX offset");
static_assert(offsetof(NiPSysDragFieldModifier, directionY) == 0x58, "directionY offset");
static_assert(offsetof(NiPSysDragFieldModifier, directionZ) == 0x5C, "directionZ offset");
