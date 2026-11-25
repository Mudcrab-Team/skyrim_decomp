// Exposure detail: (pinned-image observations; community declarations).
// Source exposure: mixed
// Code origin: original; target observations and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatInterpolator, SaveBinary, floatValue, floatData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream, SaveLinkID, oStr, NiBinaryStream, _absoluteCurrentPos, _writeFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiKeyBasedInterpolator, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

#pragma once
#include <cstdint>
class NiObject;
class NiBinaryStream
{
public:
    void* vptr;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t pad0C;
    void* _readFn;
    std::uint32_t (*_writeFn)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
class NiStream
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot0A() = 0;
    virtual void Slot0B() = 0;
    virtual void SaveLinkID(const NiObject*) = 0;
    std::uint8_t unk08[0x298];
    NiBinaryStream* oStr;
};
class NiKeyBasedInterpolator
{
public:
    void SaveBinary(NiStream&);
    std::uint8_t unk00[0x18];
};
class NiFloatInterpolator : public NiKeyBasedInterpolator
{
public:
    void SaveBinary(NiStream&);
    float floatValue;
    std::uint32_t pad1C;
    NiObject* floatData;
};
