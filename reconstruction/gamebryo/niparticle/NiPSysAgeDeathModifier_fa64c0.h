// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiPSysAgeDeathModifier, NiPSysAgeDeathModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiCloningProcess, spawnOnDeath: GUESS(low)
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

class NiPSysAgeDeathModifier : public NiPSysModifier
{
public:
    void CopyMembers(NiPSysAgeDeathModifier* a_dest, NiCloningProcess& a_process);  // compared: 0xfa64c0

    bool spawnOnDeath;  // 30
};
static_assert(offsetof(NiPSysAgeDeathModifier, spawnOnDeath) == 0x30, "spawnOnDeath offset");
