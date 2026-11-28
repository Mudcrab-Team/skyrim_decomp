// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiBinaryStream::WriteByte, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSRangeNode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SaveBinary, oStr, _absoluteCurrentPos, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// mode, first, second, WriteByte, unk08, unk0C, unk128: GUESS(low)
#pragma once

#include <cstdint>

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream* stream, const void* buffer, std::uint32_t totalBytes, std::uint32_t* componentSizes, std::uint32_t numComponents);

    void WriteByte(std::uint8_t value)
    {
        std::uint32_t componentSize = 1;
        _absoluteCurrentPos += _writeFn(this, &value, 1, &componentSize, 1);
    }

    virtual ~NiBinaryStream();

    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t unk0C;                // 0C
    void*         _readFn;              // 10
    WriteFn*      _writeFn;             // 18
};

class NiStream
{
public:
    virtual ~NiStream();

    std::uint8_t    unk08[0x298];  // 08
    NiBinaryStream* oStr;          // 2A0
};

class NiNode
{
public:
    virtual ~NiNode();
    virtual void SaveBinary(NiStream& stream);

    std::uint8_t unk08[0x120];  // 08
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");

class BSRangeNode : public NiNode
{
public:
    ~BSRangeNode() override;
    void SaveBinary(NiStream& stream) override;

    std::uint8_t unk128;  // 128
    std::uint8_t mode;    // 129
    std::uint8_t first;   // 12A
    std::uint8_t second;  // 12B
};
static_assert(sizeof(BSRangeNode) == 0x130, "BSRangeNode size");
