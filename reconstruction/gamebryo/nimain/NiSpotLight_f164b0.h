// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSpotLight: CRASHLOGGER_PDB(59818@2026.10.24)
// m_kWorldDir, m_fOuterSpotAngle, m_fInnerSpotAngle, m_fSpotExponent: SYMBOLS(fo4-pdb)
// NiPoint3, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointLight: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// baseData: GUESS(low) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    NiPoint3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {}
    float x, y, z;
};
class NiPointLight
{
public:
    NiPointLight();
    virtual ~NiPointLight();
    std::uint8_t baseData[0x148];
};
class NiSpotLight : public NiPointLight
{
public:
    NiSpotLight();
    ~NiSpotLight() override;
    NiPoint3 m_kWorldDir;
    float m_fOuterSpotAngle;
    float m_fInnerSpotAngle;
    float m_fSpotExponent;
};
static_assert(offsetof(NiSpotLight, m_kWorldDir) == 0x150, "world direction offset");
static_assert(offsetof(NiSpotLight, m_fOuterSpotAngle) == 0x15C, "outer angle offset");
static_assert(sizeof(NiSpotLight) == 0x168, "spot light size");
