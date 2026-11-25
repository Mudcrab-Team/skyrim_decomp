// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSpotLight, CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointLight, m_kWorldDir, m_fOuterSpotAngle, m_fInnerSpotAngle, m_fSpotExponent: SYMBOLS(fo4-pdb)
// unknown00, Direction: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class NiSpotLight;
class NiPointLight {
public:
    void CopyMembers(NiPointLight* destination);
    std::uint8_t unknown00[0x150];
};
struct Direction { float x, y, z; };
class NiSpotLight : public NiPointLight {
public:
    void CopyMembers(NiSpotLight* destination);
    Direction m_kWorldDir;
    float m_fOuterSpotAngle;
    float m_fInnerSpotAngle;
    float m_fSpotExponent;
};
