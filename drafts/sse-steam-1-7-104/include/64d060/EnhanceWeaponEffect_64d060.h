// 0x64d060 EnhanceWeaponEffect::ClearTargetImpl
// Code origin: original stand-in layout using CommonLibSSE-NG declarations.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnhanceWeaponEffect, ClearTargetImpl, Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect, ValueModifierEffect, MagicTarget, GetTargetAsActor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, AIProcess, currentProcess, target: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTEventSink, ActorInventoryEvent, BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterActorInventoryEventSink: SIBLING(fo4-private@1b765c70, author-permission)
// inventoryEventSink: GUESS(low); names the event-sink subobject
// unknownPrefix, unknownTail, vtable: OBSERVED

#pragma once

#include <cstddef>

class BGSLoadFormBuffer;
class ActorInventoryEvent;
template<class Event>
class BSTEventSink
{
public:
    void* vtable;
};

class AIProcess
{
public:
    void UnregisterActorInventoryEventSink(BSTEventSink<ActorInventoryEvent>* sink);
};

class Actor
{
public:
    unsigned char unknownPrefix[0xF8];
    AIProcess* currentProcess;
};
static_assert(offsetof(Actor, currentProcess) == 0xF8, "currentProcess offset");

class MagicTarget
{
public:
    Actor* GetTargetAsActor();
};

class ActiveEffect
{
public:
    void Revert(BGSLoadFormBuffer* buffer);
    unsigned char unknownPrefix[0x50];
    MagicTarget* target;
};
static_assert(offsetof(ActiveEffect, target) == 0x50, "target offset");

class ValueModifierEffect : public ActiveEffect
{
public:
    void ClearTargetImpl();
    unsigned char unknownTail[0x48];
};
static_assert(sizeof(ValueModifierEffect) == 0xA0, "event-sink base offset");

class EnhanceWeaponEffect : public ValueModifierEffect
{
public:
    void ClearTargetImpl();
    void Revert(BGSLoadFormBuffer* buffer);
    BSTEventSink<ActorInventoryEvent> inventoryEventSink;
};
