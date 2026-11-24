// Source exposure: mixed (community and sibling declarations, pinned image listing).
// Code origin: Stand-in declarations from the pinned image and labelled sources. The stream reader follows the cited sibling callbacks.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOrderedNode, NiNode, NiStream, NiBound, NiPoint3, orderedBound, useStaticBound, center, radius, flags, iStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadFn, WriteFn, _absoluteCurrentPos, _pad0C, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode, NiStream, NiBinaryStream, NiBound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the used parts of the layout
// unk00, unkF8, unkStream, SetBit: GUESS(low)
// Read: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Adapted bodies: BSOrderedNode::LoadBinary follows momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsorderednode.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsorderednode.cpp:6
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
    std::uint64_t unkStream[0x298 / 8];
    NiBinaryStream* iStr;
};

class NiNode
{
public:
    void LoadBinary(NiStream& stream);

protected:
    std::uint32_t unk00[0xF4 / 4];
    std::uint32_t flags;
    std::uint64_t unkF8[6];
};

class NiBound
{
public:
    void LoadBinary(NiStream& stream);
    float center[3];
    float radius;
};

class BSOrderedNode : public NiNode
{
public:
    void LoadBinary(NiStream& stream);

private:
    NiBound orderedBound;
    bool useStaticBound;
};
