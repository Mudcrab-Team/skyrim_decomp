// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityModifier, CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiCloningProcess, NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gravityAxis, decay, strength, forceType, turbulence, turbulenceScale, worldAligned, unk00: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class NiCloningProcess;

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class NiPSysModifier
{
public:
    void CopyMembers(NiPSysModifier* dest, NiCloningProcess& process);

    std::uint64_t unk00[7];  // 00
};
static_assert(sizeof(NiPSysModifier) == 0x38, "NiPSysModifier size");

class NiPSysGravityModifier : public NiPSysModifier
{
public:
    void CopyMembers(NiPSysGravityModifier* dest, NiCloningProcess& process);

    NiPoint3      gravityAxis;      // 38
    float         decay;            // 44
    float         strength;         // 48
    std::uint32_t forceType;        // 4C
    float         turbulence;       // 50
    float         turbulenceScale;  // 54
    bool          worldAligned;     // 58
};
static_assert(sizeof(NiPSysGravityModifier) == 0x60, "NiPSysGravityModifier size");
