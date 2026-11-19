// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial base declarations follow CommonLibSSE-NG and the offsets observed in the thunks.
// TESNPC, TESActorBase, TESBoundAnimObject, TESActorBaseData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESContainer, TESSpellList, TESAIForm, TESFullName, ActorValueOwner: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSDestructibleObjectForm, BGSSkinForm, BGSKeywordForm, BGSAttackDataForm, BGSPerkRankArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRaceForm, BGSOverridePackCollection, BSTEventSink, MenuOpenCloseEvent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// padding: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class TESBoundAnimObject
{
public:
    virtual ~TESBoundAnimObject();

private:
    std::uint8_t padding[0x28];
};

class TESActorBaseData
{
public:
    virtual ~TESActorBaseData();

private:
    std::uint8_t padding[0x50];
};

class TESContainer
{
public:
    virtual ~TESContainer();

private:
    std::uint8_t padding[0x10];
};

class TESSpellList
{
public:
    virtual ~TESSpellList();

private:
    std::uint8_t padding[0x8];
};

class TESAIForm
{
public:
    virtual ~TESAIForm();

private:
    std::uint8_t padding[0x20];
};

class TESFullName
{
public:
    virtual ~TESFullName();

private:
    std::uint8_t padding[0x8];
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
};

class BGSDestructibleObjectForm
{
public:
    virtual ~BGSDestructibleObjectForm();

private:
    std::uint8_t padding[0x8];
};

class BGSSkinForm
{
public:
    virtual ~BGSSkinForm();

private:
    std::uint8_t padding[0x8];
};

class BGSKeywordForm
{
public:
    virtual ~BGSKeywordForm();

private:
    std::uint8_t padding[0x10];
};

class BGSAttackDataForm
{
public:
    virtual ~BGSAttackDataForm();

private:
    std::uint8_t padding[0x8];
};

class BGSPerkRankArray
{
public:
    virtual ~BGSPerkRankArray();

private:
    std::uint8_t padding[0x10];
};

class TESActorBase :
    public TESBoundAnimObject,
    public TESActorBaseData,
    public TESContainer,
    public TESSpellList,
    public TESAIForm,
    public TESFullName,
    public ActorValueOwner,
    public BGSDestructibleObjectForm,
    public BGSSkinForm,
    public BGSKeywordForm,
    public BGSAttackDataForm,
    public BGSPerkRankArray
{
public:
    TESActorBase();
    ~TESActorBase() override;
};
static_assert(sizeof(TESActorBase) == 0x150, "TESActorBase size");

class TESRaceForm
{
public:
    virtual ~TESRaceForm();

private:
    std::uint8_t padding[0x8];
};

class BGSOverridePackCollection
{
public:
    virtual ~BGSOverridePackCollection();

private:
    std::uint8_t padding[0x20];
};

struct MenuOpenCloseEvent;

template <class Event>
class BSTEventSink
{
public:
    virtual ~BSTEventSink();
};

class TESNPC :
    public TESActorBase,
    public TESRaceForm,
    public BGSOverridePackCollection,
    public BSTEventSink<MenuOpenCloseEvent>
{
public:
    TESNPC();
    ~TESNPC() override;
};
