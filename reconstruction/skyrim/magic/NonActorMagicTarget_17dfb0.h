// Source exposure: mixed
// Code origin: original declaration view from the pinned image and labelled community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NonActorMagicTarget, NonActorMagicTarget::~NonActorMagicTarget, NonActorMagicTarget::targetObject, NonActorMagicTarget::activeEffects: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, MagicTarget, TESObjectREFR, ActiveEffect, BSSimpleList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData::~BSExtraData, BSExtraData::next, MagicTarget::~MagicTarget, MagicTarget::postUpdateDispelList, BSSimpleList::~BSSimpleList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unkMagicTarget10, unkListStorage: GUESS(low)
#pragma once

#include <cstddef>

class TESObjectREFR;
class ActiveEffect;
class SpellDispelData;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    BSExtraData* next;
};

class MagicTarget
{
public:
    virtual ~MagicTarget();
    SpellDispelData* postUpdateDispelList;
    unsigned char unkMagicTarget10[8];
};

template <class T>
class BSSimpleList
{
public:
    ~BSSimpleList();

private:
    T unkListStorage[2];
};

class NonActorMagicTarget : public BSExtraData, public MagicTarget
{
public:
    NonActorMagicTarget();
    ~NonActorMagicTarget() override;

    TESObjectREFR* targetObject;
    BSSimpleList<ActiveEffect*> activeEffects;
};

static_assert(offsetof(NonActorMagicTarget, activeEffects) == 0x30, "Active effect list offset");
static_assert(sizeof(NonActorMagicTarget) == 0x40, "Size for sized deallocation");
