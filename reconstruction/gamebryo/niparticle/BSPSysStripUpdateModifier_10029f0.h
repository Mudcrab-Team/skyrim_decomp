// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier: EXE_RTTI
// NiPSysModifier, NiStream, NiBinaryStream, SaveBinary, oStr, _absoluteCurrentPos, _writeFn, WriteFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fUpdateDeltaTime: SYMBOLS(fo4-pdb)
// NiPSysModifier, NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only accessed fields are represented.
// unknown00, unknownVtable, unknown0C, unknown10: GUESS(low); unrepresented storage.
#pragma once
#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    void* unknownVtable;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t unknown0C;
    void* unknown10;
    WriteFn* _writeFn;
};
class NiStream
{
public:
    unsigned char unknown00[0x2A0];
    NiBinaryStream* oStr;
};
class NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream);
    unsigned char unknown00[0x30];
};
class BSPSysStripUpdateModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream);
    float fUpdateDeltaTime;
};
static_assert(offsetof(BSPSysStripUpdateModifier, fUpdateDeltaTime) == 0x30, "update interval offset");
static_assert(offsetof(NiStream, oStr) == 0x2A0, "output stream offset");
static_assert(offsetof(NiBinaryStream, _writeFn) == 0x18, "write callback offset");
