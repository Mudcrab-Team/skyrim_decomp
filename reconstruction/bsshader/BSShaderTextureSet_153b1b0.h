// Source exposure: mixed (community and sibling declarations, pinned image listing).
// Code origin: Stand-in declarations from the pinned image and labelled sources. The stream reader follows the cited sibling callbacks.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderTextureSet, LoadBinary, textures, NiObject, NiStream, NiBinaryStream, iStr, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadFn, WriteFn, _absoluteCurrentPos, _pad0C, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); fields and calls used by this unit
// unk00, unk10, unkStream, LoadFixedStringLegacy: GUESS(low)
// Read: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Adapted bodies: BSShaderTextureSet::LoadBinary follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:45
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:29
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp:678
#pragma once

#include <cstdint>

class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    template <class T>
    void Read(T& value)
    {
        std::uint32_t componentSize = sizeof(T);
        _absoluteCurrentPos += _readFn(this, &value, sizeof(T), &componentSize, 1);
    }

    std::uint64_t unk00;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t _pad0C;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};

class NiStream
{
public:
    void LoadFixedStringLegacy(const char*& value);
    std::uint64_t unkStream[0x298 / 8];
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
};

class NiObject
{
public:
    void LoadBinary(NiStream& stream);

private:
    std::uint64_t unk00;
    std::uint64_t unk10;
};

class BSShaderTextureSet : public NiObject
{
public:
    void LoadBinary(NiStream& stream);

private:
    const char* textures[9];
};
