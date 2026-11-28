// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysInheritVelocityModifier, CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionfa0f00, unk08, unk30, unk54, unk58, unk5C: GUESS(low)
#pragma once

#include <cstdint>

class NiPSysModifier
{
public:
    virtual ~NiPSysModifier();

    void Functionfa0f00(NiPSysModifier* destination);

    std::uint8_t unk08[0x28];  // 08
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSPSysInheritVelocityModifier : public NiPSysModifier
{
public:
    void CopyMembers(BSPSysInheritVelocityModifier* destination);

    std::uint8_t unk30[0x24];  // 30
    float        unk54;        // 54
    float        unk58;        // 58
    float        unk5C;        // 5C
};
static_assert(sizeof(BSPSysInheritVelocityModifier) == 0x60, "BSPSysInheritVelocityModifier size");
