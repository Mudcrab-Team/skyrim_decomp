// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESActorBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESActorBase::GetIsPlayerOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESActorBase::IsAutoCalc, TESActorBase::SetAutoCalc, TESActorBase::~TESActorBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESActorBaseData::SetFlagBit: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class TESBoundAnimObject : public TESBoundObject
{
public:
};

class TESActorBaseData
{
public:
    void SetFlagBit(std::uint32_t a_bit, bool a_value, bool a_unknown);
};

class TESCombatStyle;

class TESActorBase : public TESBoundAnimObject
{
public:
    TESActorBase();
    virtual bool GetIsPlayerOwner() const;  // compared: 0x3b03a0
    virtual bool IsAutoCalc() const;  // compared: 0x3afed0
    virtual void SetAutoCalc(bool a_autoCalc);  // compared: 0x3afef0
    // GetCombatStyle, GetHasPLSpecTex: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // RestoreActorValue argument types: GUESS(low)
    virtual TESCombatStyle* GetCombatStyle();
    virtual bool GetHasPLSpecTex() const;
    virtual void RestoreActorValue(std::uint32_t a_modifier, std::uint32_t a_akValue, float a_value);
    virtual ~TESActorBase();  // compared: 0x3cbc60 (scalar deleting destructor)

    std::uint8_t padding[0x130];
};
