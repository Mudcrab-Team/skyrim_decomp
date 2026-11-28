// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysDragModifier, NiPSysDragModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiCloningProcess, unk30, dragAxisX, dragAxisY, dragAxisZ, percentage, range, rangeFalloff: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiCloningProcess;

class NiPSysModifier
{
public:
    virtual ~NiPSysModifier();
    void CopyMembers(NiPSysModifier* a_dest, NiCloningProcess& a_process);

    std::uint8_t unk08[0x28];  // 08
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class NiPSysDragModifier : public NiPSysModifier
{
public:
    void CopyMembers(NiPSysDragModifier* a_dest, NiCloningProcess& a_process);  // compared: 0xfac7a0

    std::uint64_t unk30;  // 30
    float dragAxisX;  // 38
    float dragAxisY;  // 3C
    float dragAxisZ;  // 40
    float percentage;  // 44
    float range;  // 48
    float rangeFalloff;  // 4C
};
static_assert(offsetof(NiPSysDragModifier, dragAxisX) == 0x38, "dragAxisX offset");
static_assert(offsetof(NiPSysDragModifier, rangeFalloff) == 0x4C, "rangeFalloff offset");
