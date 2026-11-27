// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticleMeshes, NiParticleMeshes::NiParticleMeshes: CRASHLOGGER_PDB(59818@2026.10.24)
// NiParticles: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// unknown008, meshCount, updateMeshes: GUESS(low)
#pragma once
#include <cstdint>

class NiParticles
{
public:
    NiParticles();
    virtual ~NiParticles();
    std::uint8_t unknown008[0x160];
};
class NiParticleMeshes : public NiParticles
{
public:
    NiParticleMeshes();
    virtual ~NiParticleMeshes();
    std::uint32_t meshCount;
    bool updateMeshes;
};
static_assert(sizeof(NiParticles) == 0x168, "base extent");
