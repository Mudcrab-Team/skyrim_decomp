// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations. Stamped as a twin of matched 0xf12a70 (bssystem/NiStream_19e930): source copied, names replaced by placeholders.
// ::iStr, ::oStr, ::registerMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::Load3, ::GetLinkIDFromObject, ::SaveLinkID, ::LoadStream, ::RegisterObjects, ::SaveTopLevelObjects, ::PreSaveObjectSizeTable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionf1b840, Ownerf1b840: GUESS(low) STANDIN
// objectCount, topObjectCount, loadState, loadContext, LoadFromInputPath, WriteIntegers, ClearLoadContext: GUESS(low) STANDIN
#pragma once
#include "NiStream_19e930.h"
#include <cstring>

class Ownerf1b840
{
public:
    virtual ~Ownerf1b840();
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
    void Functionf1b840(std::uint32_t* values, std::uint32_t count);
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

