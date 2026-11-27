// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBoxEmitter, NiPSysBoxEmitter::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysVolumeEmitter, NiPSysVolumeEmitter::LoadBinary: STANDIN OBSERVED
// m_fEmitterWidth, m_fEmitterHeight, m_fEmitterDepth: SYMBOLS(fo4-pdb)
// NiBinaryStream, NiStream, read, write: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// vtable, position, input, output, unknown00, unknown0c: STANDIN GUESS(low); descriptive fields at observed offsets
#pragma once
#include <cstddef>
#include <cstdint>
class NiBinaryStream
{
public:
    void* vtable;
    std::uint32_t position;
    std::uint32_t unknown0c;
    std::uint32_t (*read)(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t (*write)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
class NiStream
{
public:
    std::uint8_t unknown00[0x298];
    NiBinaryStream* input;
    NiBinaryStream* output;
};
class NiPSysVolumeEmitter
{
public:
    void LoadBinary(NiStream& stream);
    std::uint8_t unknown00[0x78];
};
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
public:
    void LoadBinary(NiStream& stream);
    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float m_fEmitterDepth;
};
static_assert(offsetof(NiStream, input) == 0x298, "Observed input stream offset");
static_assert(offsetof(NiStream, output) == 0x2a0, "Observed output stream offset");
static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "Observed volume emitter base extent");
