// Source exposure: mixed (pinned-image observations; community and sibling symbol declarations).
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBoundUpdateModifier, NiPSysBoundUpdateModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiPSysModifier::SaveBinary: STANDIN SYMBOLS(tesv-2013-map)
// NiPSysBoundUpdateModifier::SaveBinary, m_sUpdateSkip: SYMBOLS(fo4-pdb)
// NiBinaryStream, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// read, write: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// vtable, position, output, input, unknown00, unknown0c: STANDIN GUESS(low); descriptive fields at observed offsets
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
class NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream);
    std::uint8_t unknown00[0x30];
};
class NiPSysBoundUpdateModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream);
    std::int16_t m_sUpdateSkip;
};
static_assert(offsetof(NiStream, output) == 0x2a0, "Observed output stream offset");
static_assert(sizeof(NiPSysModifier) == 0x30, "Observed modifier base extent");
