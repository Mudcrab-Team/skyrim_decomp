// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiBinaryStream::WriteValue, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNodeReferences: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject, NiObject, NiAVObject, NiNode, NiTArray, NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SaveBinary, SaveLinkID, Unk_07, oStr, parent, _data, _capacity, _freeIdx, _size, _growthSize, _absoluteCurrentPos, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// nodes, WriteValue, unk08, unk0C, unk10, Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_08, Unk_09, Unk_0A, Unk_0B: GUESS(low)
#pragma once

#include <cstdint>

class NiNode;
class NiStream;

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream* stream, const void* buffer, std::uint32_t totalBytes, std::uint32_t* componentSizes, std::uint32_t numComponents);

    template <class T>
    void WriteValue(const T* value)
    {
        std::uint32_t componentSize = sizeof(T);
        _absoluteCurrentPos += _writeFn(this, value, sizeof(T), &componentSize, 1);
    }

    virtual ~NiBinaryStream();

    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t unk0C;                // 0C
    void*         _readFn;              // 10
    WriteFn*      _writeFn;             // 18
};

class NiRefObject
{
public:
    virtual ~NiRefObject();

    std::uint8_t unk08[0x8];  // 08
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    ~NiObject() override;
    virtual void SaveBinary(NiStream& stream);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiAVObject : public NiObject
{
public:
    ~NiAVObject() override;

    std::uint8_t unk10[0x20];  // 10
    NiNode*      parent;       // 30
};
static_assert(sizeof(NiAVObject) == 0x38, "NiAVObject size");

class NiNode : public NiAVObject
{
};

template <class T>
class NiTArray
{
public:
    virtual ~NiTArray();

    T*            _data;        // 08
    std::uint16_t _capacity;    // 10
    std::uint16_t _freeIdx;     // 12
    std::uint16_t _size;        // 14
    std::uint16_t _growthSize;  // 16
};
static_assert(sizeof(NiTArray<NiAVObject*>) == 0x18, "NiTArray size");

class NiStream
{
public:
    virtual ~NiStream();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void SaveLinkID(const NiObject* object);

    std::uint8_t    unk08[0x298];  // 08
    NiBinaryStream* oStr;          // 2A0
};

class BSNodeReferences : public NiObject
{
public:
    ~BSNodeReferences() override;
    void SaveBinary(NiStream& stream) override;

    NiTArray<NiAVObject*> nodes;  // 10
};
static_assert(sizeof(BSNodeReferences) == 0x28, "BSNodeReferences size");
