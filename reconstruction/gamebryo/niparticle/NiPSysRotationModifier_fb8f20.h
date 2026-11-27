// Source exposure: mixed (community declarations; pinned image observations; sibling symbol declarations).
// Code origin: original; minimal declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysRotationModifier, NiPSysRotationModifier::PostLinkObject: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// NiPSysModifier, NiParticleSystem, NiPSysData, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// target, particleData, rotationSpeeds, numVertices, nifMaxVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED
// NiPSysModifier::PostLinkObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_fInitialRotSpeed: SYMBOLS(fo4-pdb) OBSERVED
// unknown00, unknown7E, unknownA, unknownB: GUESS(low); unused storage before observed fields
#pragma once
#include <cstdint>
#include <cstddef>
struct NiStream {
    std::uint8_t unknown00[0x100];
    std::uint32_t nifMaxVersion;
};
struct NiPSysData {
    std::uint8_t unknown00[0x7C];
    std::uint16_t numVertices;
    std::uint8_t unknown7E[0x1A];
    float* rotationSpeeds;
};
struct NiParticleSystem {
    std::uint8_t unknown00[0x158];
    NiPSysData* particleData;
};
class NiPSysModifier {
public:
    void PostLinkObject(NiStream& stream);
    std::uint8_t unknownA[0x20];
    NiParticleSystem* target;
    std::uint8_t unknownB[8];
};
class NiPSysRotationModifier : public NiPSysModifier {
public:
    void PostLinkObject(NiStream& stream);
    float m_fInitialRotSpeed;
};
static_assert(offsetof(NiPSysData, rotationSpeeds) == 0x98, "Observed speed array offset");
static_assert(sizeof(NiPSysModifier) == 0x30, "Observed modifier base extent");
