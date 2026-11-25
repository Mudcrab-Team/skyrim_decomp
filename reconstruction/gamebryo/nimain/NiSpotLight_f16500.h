// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed layout and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSpotLight, NiSpotLight::UpdateWorldData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, NiMatrix3, NiUpdateData, entry, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_kWorldDir: SYMBOLS(fo4-pdb)
// unknown00, unknownA0, worldRotation, UpdateInheritedWorldData: GUESS(low) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>

class NiUpdateData;
struct NiPoint3
{
    float x, y, z;
};
struct NiMatrix3
{
    float entry[3][3];
};

class NiSpotLight
{
public:
    void UpdateWorldData(NiUpdateData* data);
    std::uint8_t unknown00[0x7C];
    NiMatrix3 worldRotation;
    std::uint8_t unknownA0[0xB0];
    NiPoint3 m_kWorldDir;
};
static_assert(offsetof(NiSpotLight, worldRotation) == 0x7C, "world rotation offset");
static_assert(offsetof(NiSpotLight, m_kWorldDir) == 0x150, "world direction offset");

void UpdateInheritedWorldData(NiSpotLight* light, NiUpdateData* data);
