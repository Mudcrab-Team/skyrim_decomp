// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiStream: EXE_RTTI
// NiStream::inputFilePath, ::iStr, ::oStr, ::registerMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::Load1, ::Load3, ::GetLinkIDFromObject, ::SaveLinkID, ::LoadStream, ::RegisterObjects, ::SaveTopLevelObjects, ::PreSaveObjectSizeTable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// objectCount, topObjectCount, loadState, loadContext, LoadFromInputPath, ReadIntegers, WriteIntegers, ClearLoadContext: GUESS(low)
#pragma once

#include "gamebryo/nianimation/NiInterpolator.h"

class BSFixedString;

// NiBinaryStream, NiBinaryStream::good, ::tell, ::_absoluteCurrentPos, ::_readFn, ::_writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    virtual ~NiBinaryStream();
    virtual bool good() const;
    virtual void seek(std::int32_t offset);
    virtual std::uint32_t tell() const;

    std::uint32_t _absoluteCurrentPos;
    std::uint32_t padding0C;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};

// StreamLoadContext, ObjectLinkTable, LinkEntry, slots and fields: STANDIN GUESS(low)
class StreamLoadContext
{
public:
    virtual ~StreamLoadContext();
};

struct LinkEntry
{
    LinkEntry* next;
    const NiObject* object;
    std::uint32_t id;
};

class ObjectLinkTable
{
public:
    virtual ~ObjectLinkTable();
    virtual std::uint32_t BucketFor(const NiObject* object) const;
    virtual bool IsSameObject(const NiObject* a, const NiObject* b) const;

    std::uint8_t padding08[0x8];
    LinkEntry** buckets;
    std::uint32_t count;
};
static_assert(sizeof(ObjectLinkTable) == 0x20, "link table size");

class NiStream
{
public:
    virtual ~NiStream();
    virtual bool Load1(NiBinaryStream* stream);
    virtual bool Load2(char* buffer, std::uint64_t size);
    virtual bool Load3(const char* path);
    virtual bool Save1(NiBinaryStream* stream);
    virtual bool Save2(char*& buffer, std::uint64_t& size);
    virtual bool Save3(const char* path);
    virtual void Slot07();
    virtual bool RegisterFixedString(const BSFixedString& name);
    virtual bool RegisterSaveObject(NiObject* object);
    virtual bool ChangeObject(NiObject* object);
    virtual std::uint32_t GetLinkIDFromObject(const NiObject* object);
    virtual void SaveLinkID(const NiObject* object);
    virtual bool LoadHeader();
    virtual void SaveHeader();
    virtual bool LoadStream();
    virtual void SaveStream();
    virtual void RegisterObjects();
    virtual void LoadTopLevelObjects();
    virtual void SaveTopLevelObjects();
    virtual bool LoadObject();
    // The return type follows the pinned stream position width.
    virtual std::uint32_t PreSaveObjectSizeTable();
    bool LoadFromInputPath();
    void ClearLoadContext();
    void ReadIntegers(std::uint32_t* values, std::uint32_t count);
    void WriteIntegers(const std::uint32_t* values, std::uint32_t count);

private:
    std::uint8_t padding08[0x100];
    char inputFilePath[260];
    std::uint8_t padding20C[0x20];
    std::uint32_t objectCount;
    std::uint8_t padding230[0x30];
    NiObject** topObjects;
    std::uint32_t padding268;
    std::uint32_t topObjectCount;
    std::uint8_t padding270[0x28];

public:
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;

private:
    std::uint8_t padding2A8[0x8];
    ObjectLinkTable registerMap;
    std::uint8_t padding2D0[0x8];
    std::uint32_t loadState;
    std::uint8_t padding2DC[0x14];
    StreamLoadContext* loadContext;
};
