// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the caster prefix and animation bases follow the cited declarations and pinned offsets.
// ActorMagicCaster, SimpleAnimationGraphManagerHolder, BSTEventSink, BGSArtObject, BSLight, actor, castingArt, light, castingSource, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, LightPointer, padding, EventSinkPrefix: STANDIN GUESS(low)
#pragma once

#include "MagicCaster_5cd1b0.h"

class BGSArtObject;
class BSLight;

class SimpleAnimationGraphManagerHolder
{
public:
    virtual ~SimpleAnimationGraphManagerHolder();

private:
    std::uint8_t padding08[0x10];
};

class EventSinkPrefix
{
public:
    virtual ~EventSinkPrefix();
};

class LightPointer
{
public:
    LightPointer& Function150cb10(BSLight* source);

private:
    BSLight* pointer;
};

class ActorMagicCaster : public MagicCaster, public SimpleAnimationGraphManagerHolder, public EventSinkPrefix
{
public:
    void Function5c0700();
    bool Function5c0860() const;
    void Function5c08b0(BGSArtObject* art);
    void Function5c1060();
    void Function5c10c0();
    TESForm* Function5c1270() const;
    LightPointer& Function5c17e0(LightPointer& output) const;
    void Function5cd900(MagicItem* spell);
    void Function5cdb10(std::uint32_t index);
    void Function5cdc00();

private:
    void Function5c0cd0();

    std::uint8_t padding068[0x50];
    Actor* actor;
    std::uint8_t padding0C0[8];
    BSLight* light;
    std::uint8_t padding0D0[0x10];
    BGSArtObject* castingArt;
    std::uint8_t padding0E8[0xC];
    MagicSystem::CastingSource castingSource;
    std::uint32_t flags;
};
static_assert(sizeof(ActorMagicCaster) == 0x100, "actor caster layout size");
