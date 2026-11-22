// Source exposure: mixed (community headers and the pinned image).
// Code origin: project stand-ins and the community declarations labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActorBase, ActorValueOwner, GetIsPlayerOwner, IsAutoCalc, SetAutoCalc, ~TESActorBase, GetCombatStyle, GetHasPLSpecTex: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject, TESActorBaseComponents: STANDIN EXE_RTTI
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

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual bool GetIsPlayerOwner() const;
};
static_assert(sizeof(ActorValueOwner) == 0x8, "ActorValueOwner size");

class TESActorBaseComponents
{
public:
    virtual void ComponentStub();
    std::uint8_t data[0xC0];
};
static_assert(sizeof(TESActorBaseComponents) == 0xC8, "TESActorBaseComponents size");

class TESCombatStyle;

class TESActorBase : public TESBoundAnimObject, public TESActorBaseComponents, public ActorValueOwner
{
public:
    TESActorBase();
    bool GetIsPlayerOwner() const override;  // compared: 0x3b03a0
    virtual bool IsAutoCalc() const;  // compared: 0x3afed0
    virtual void SetAutoCalc(bool a_autoCalc);  // compared: 0x3afef0
    virtual TESCombatStyle* GetCombatStyle();
    virtual bool GetHasPLSpecTex() const;
    virtual void RestoreActorValue(std::uint32_t a_modifier, std::uint32_t a_akValue, float a_value);
    virtual ~TESActorBase();  // compared: 0x3cbc60 (scalar deleting destructor)

    std::uint8_t trailingData[0x60];
};
static_assert(sizeof(TESActorBase) == 0x150, "TESActorBase size");
