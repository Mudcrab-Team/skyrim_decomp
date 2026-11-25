// Source exposure: mixed (community names; pinned image observations; sibling symbol declarations).
// Code origin: original; minimal declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBoxEmitter, NiPSysBoxEmitter::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// NiPSysEmitter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysEmitter::CopyMembers: GUESS(low); inferred base-copy boundary
// NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_fEmitterWidth, m_fEmitterHeight, m_fEmitterDepth: SYMBOLS(fo4-pdb) OBSERVED
#pragma once
#include <cstddef>
#include <cstdint>
class NiCloningProcess;
class NiPSysEmitter
{
public:
    void CopyMembers(NiPSysEmitter* destination, NiCloningProcess& cloning);
    std::uint8_t unknownBase[120];
};
class NiPSysBoxEmitter : public NiPSysEmitter
{
public:
    void CopyMembers(NiPSysBoxEmitter* destination, NiCloningProcess& cloning);
    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float m_fEmitterDepth;
};
static_assert(sizeof(NiPSysEmitter) == 120, "Observed emitter base extent");
