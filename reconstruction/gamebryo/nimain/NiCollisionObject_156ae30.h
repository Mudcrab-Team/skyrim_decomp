// Source exposure: mixed (community headers; pinned-image observations).
// Code origin: original; community declarations and observed behavior
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCollisionObject::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCollisionObject, NiCollisionObject::SaveBinary, NiCollisionObject::sceneObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream, NiStream::Load1, NiStream::Load2, NiStream::Load3, NiStream::Save1, NiStream::Save2, NiStream::Save3, NiStream::Unk_07, NiStream::RegisterFixedString, NiStream::RegisterSaveObject, NiStream::ChangeObject, NiStream::GetLinkIDFromObject, NiStream::SaveLinkID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "declarations/NiObject.h"

// Opaque scene-object subtype; only its NiObject base is used here.
class NiAVObject : public NiObject {};
class NiBinaryStream;
class BSFixedString;

class NiStream
{
public:
    virtual ~NiStream();
    virtual bool Load1(NiBinaryStream*);
    virtual bool Load2(char*, std::uint64_t);
    virtual bool Load3(const char*);
    virtual bool Save1(NiBinaryStream*);
    virtual bool Save2(char*&, std::uint64_t&);
    virtual bool Save3(const char*);
    virtual void Unk_07();
    virtual bool RegisterFixedString(const BSFixedString&);
    virtual bool RegisterSaveObject(NiObject*);
    virtual bool ChangeObject(NiObject*);
    virtual std::uint32_t GetLinkIDFromObject(const NiObject*);
    virtual void SaveLinkID(const NiObject*);
};

class NiCollisionObject : public NiObject
{
public:
    void SaveBinary(NiStream& stream) override;
    NiAVObject* sceneObject; // 0x10
};
static_assert(sizeof(NiCollisionObject) == 0x18, "NiCollisionObject size");
