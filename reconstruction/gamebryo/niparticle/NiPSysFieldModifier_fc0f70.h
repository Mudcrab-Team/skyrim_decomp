// Source exposure: mixed (community declarations; local target observations; sibling symbol facts).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysFieldModifier, NiPSysFieldModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "NiPSysModifier.h"
#include <cstddef>

class NiPSysFieldModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream) override;
    // m_pkFieldObj, m_fMagnitude, m_fAttenuation, m_bUseMaxDistance, m_fMaxDistance: SYMBOLS(fo4-pdb)
    NiObject* m_pkFieldObj;
    float m_fMagnitude;
    float m_fAttenuation;
    bool m_bUseMaxDistance;
    // unknown41: GUESS(low)
    std::uint8_t unknown41[3];
    float m_fMaxDistance;
};
static_assert(offsetof(NiPSysFieldModifier, m_pkFieldObj) == 0x30, "field object offset");
static_assert(offsetof(NiPSysFieldModifier, m_fMagnitude) == 0x38, "magnitude offset");
static_assert(offsetof(NiPSysFieldModifier, m_bUseMaxDistance) == 0x40, "distance toggle offset");
static_assert(offsetof(NiPSysFieldModifier, m_fMaxDistance) == 0x44, "maximum distance offset");
