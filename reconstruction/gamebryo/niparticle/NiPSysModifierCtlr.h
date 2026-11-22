// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// Code origin: SaveBinary original from the pinned image listing and the community declarations below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierCtlr: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// NiPSysModifierCtlr::SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiObject, NiInterpolator, NiTimeController, NiInterpController, NiSingleInterpController: STANDIN EXE_RTTI; no members, only the virtuals these units name
// NiTimeController::SaveBinary, NiTimeController::Stop, NiStream, SaveLinkID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); SaveLinkID is stream slot 0C
// unk01..unk0B: GUESS(low); stream slots kept only to place SaveLinkID
// SaveFixedString: GUESS(low); the non-virtual callee that writes the interned name held in member
#pragma once
#include <cstdint>

class NiObject
{
public:
    virtual ~NiObject();
};

class NiInterpolator : public NiObject
{
};

class NiStream
{
public:
    virtual ~NiStream();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void SaveLinkID(const NiObject* object);  // 0C

    void SaveFixedString(void* const& string);
};

class NiTimeController : public NiObject
{
public:
    virtual void SaveBinary(NiStream& stream);
    virtual void Stop();
};

class NiInterpController : public NiTimeController
{
};

class NiSingleInterpController : public NiInterpController
{
public:
    void SaveBinary(NiStream& stream) override;
};

// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class NiPSysModifierCtlr : public NiSingleInterpController
{
public:
    virtual void* GetCtlrID() const;
    void SaveBinary(NiStream& stream) override;
    std::uint8_t padding[0x48];
    void* member;
};
