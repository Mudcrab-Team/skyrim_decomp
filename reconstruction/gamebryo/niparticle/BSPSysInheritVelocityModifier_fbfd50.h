// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysInheritVelocityModifier: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysModifier, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsEqual, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk10, unk30, unk38, unk44, unk50, unk54, unk58, unk5C: GUESS(low)
#pragma once

#include <cstdint>

class NiPoint3
{
public:
    bool operator==(const NiPoint3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class NiObject
{
public:
    virtual ~NiObject();
    virtual bool IsEqual(NiObject* object);

    std::uint8_t unk08[0x8];  // 08
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiPSysModifier : public NiObject
{
public:
    ~NiPSysModifier() override;
    bool IsEqual(NiObject* object) override;

    std::uint8_t unk10[0x20];  // 10
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSPSysInheritVelocityModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object) override;

    std::uint8_t unk30[0x8];  // 30
    NiPoint3     unk38;       // 38
    NiPoint3     unk44;       // 44
    float        unk50;       // 50
    float        unk54;       // 54
    float        unk58;       // 58
    float        unk5C;       // 5C
};
static_assert(sizeof(BSPSysInheritVelocityModifier) == 0x60, "BSPSysInheritVelocityModifier size");
