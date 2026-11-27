// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiPSysGrowFadeModifier, NiPSysGrowFadeModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, NiPSysModifier, NiPSysModifier::CopyMembers, growTime, growGeneration, unk36, fadeTime, fadeGeneration, unk3E, baseScale, unk00: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiCloningProcess;

class NiPSysModifier
{
public:
    void CopyMembers(NiPSysModifier* a_dest, NiCloningProcess& a_clone);

    std::uint8_t unk00[0x30];
};

class NiPSysGrowFadeModifier : public NiPSysModifier
{
public:
    void CopyMembers(NiPSysGrowFadeModifier* a_dest, NiCloningProcess& a_clone);

    float growTime;
    std::uint16_t growGeneration;
    std::uint16_t unk36;
    float fadeTime;
    std::uint16_t fadeGeneration;
    std::uint16_t unk3E;
    float baseScale;
};

static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");
static_assert(offsetof(NiPSysGrowFadeModifier, growTime) == 0x30, "growTime offset");
static_assert(offsetof(NiPSysGrowFadeModifier, growGeneration) == 0x34, "growGeneration offset");
static_assert(offsetof(NiPSysGrowFadeModifier, fadeTime) == 0x38, "fadeTime offset");
static_assert(offsetof(NiPSysGrowFadeModifier, fadeGeneration) == 0x3C, "fadeGeneration offset");
static_assert(offsetof(NiPSysGrowFadeModifier, baseScale) == 0x40, "baseScale offset");
