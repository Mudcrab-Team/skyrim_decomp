// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// BGSDestructibleObjectForm, BGSDestructibleObjectForm::sub_1401834A0: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectREFR, Actor, ActorValueOwner, DestructibleObjectData, formType, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// health, TESObjectREFR::AsActor, unk00, unk08, unk1B, unk20: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class Actor;

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(std::uint32_t a_akValue);
    virtual float GetPermanentActorValue(std::uint32_t a_akValue);
    virtual float GetBaseActorValue(std::uint32_t a_akValue);
};
static_assert(sizeof(ActorValueOwner) == 0x08, "ActorValueOwner size");

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();

    // This reference as an actor, or null when its form type is not the actor type.
    Actor* AsActor();

    std::uint8_t unk08[0x1A - 0x08];
    std::uint8_t formType;
    std::uint8_t unk1B[0xB8 - 0x1B];
};
static_assert(offsetof(TESObjectREFR, formType) == 0x1A, "TESObjectREFR::formType offset");
static_assert(sizeof(TESObjectREFR) == 0xB8, "TESObjectREFR size");

class Actor : public TESObjectREFR, public ActorValueOwner
{
public:
};
static_assert(sizeof(Actor) == 0xC0, "Actor size");

inline Actor* TESObjectREFR::AsActor()
{
    return formType == 0x3E ? static_cast<Actor*>(this) : nullptr;
}

struct DestructibleObjectData
{
    std::uint32_t health;
};

class BGSDestructibleObjectForm
{
public:
    std::uint32_t sub_1401834A0(TESObjectREFR* a_refr) const;

    std::uint8_t unk00[0x08];
    DestructibleObjectData* data;
};
static_assert(offsetof(BGSDestructibleObjectForm, data) == 0x08, "BGSDestructibleObjectForm::data offset");
