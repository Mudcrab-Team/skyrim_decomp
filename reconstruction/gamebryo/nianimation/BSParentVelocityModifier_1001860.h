// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPSysModifier, BSParentVelocityModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSParentVelocityModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier::CopyMembers, NiPSysModifier::unk00, BSParentVelocityModifier::unk30, BSParentVelocityModifier::damping: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiPSysModifier
{
public:
    void CopyMembers(NiPSysModifier* a_dest, void* a_process);

    std::uint8_t unk00[0x30];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSParentVelocityModifier : public NiPSysModifier
{
public:
    void CopyMembers(BSParentVelocityModifier* a_dest, void* a_process);

    std::uint8_t unk30[0x08];
    float damping;
};
static_assert(offsetof(BSParentVelocityModifier, damping) == 0x38, "damping offset");
