// Source exposure: mixed (community declarations; local target observations; sibling symbol facts).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSpotLight, NiSpotLight::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "NiPointLight.h"

class NiSpotLight : public NiPointLight
{
public:
    void LoadBinary(NiStream& stream) override;
    // m_kWorldDir, m_fOuterSpotAngle, m_fInnerSpotAngle, m_fSpotExponent: SYMBOLS(fo4-pdb)
    // Member offsets: OBSERVED
    float m_kWorldDir[3];
    float m_fOuterSpotAngle;
    float m_fInnerSpotAngle;
    float m_fSpotExponent;
};
static_assert(offsetof(NiSpotLight, m_fOuterSpotAngle) == 0x15C, "outer angle offset");
static_assert(offsetof(NiSpotLight, m_fInnerSpotAngle) == 0x160, "inner angle offset");
static_assert(offsetof(NiSpotLight, m_fSpotExponent) == 0x164, "exponent offset");
