// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSActionData.h
// BGSActionData, ActionInput, ActionOutput, BSFixedString, ~ActionInput, source, target, action, unk20, animEvent, targetAnimEvent, result, sequence, animObjIdle, sequenceIndex, flags, Clone, Process, GetSourceActorState, Unk_02, GetSourceSequencer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSActionData::~BGSActionData: SIBLING(fo4-private@1b765c70, author-permission)
// TESObjectREFR, BGSAction, TESIdleForm, ActorState, BGSAnimationSequencer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class TESObjectREFR;
class BGSAction;
class TESIdleForm;
class ActorState;
class BGSAnimationSequencer;

struct BSFixedString
{
    ~BSFixedString();

    const char* data;  // 00
};

class ActionInput
{
public:
    ActionInput();
    virtual ~ActionInput();  // 00
    virtual ActorState* GetSourceActorState() const;  // 01
    virtual void Unk_02();  // 02
    virtual BGSAnimationSequencer* GetSourceSequencer() const;  // 03

    TESObjectREFR* source;  // 08
    TESObjectREFR* target;  // 10
    BGSAction* action;  // 18
    std::uint32_t unk20;  // 20
    std::uint32_t pad24;  // 24
};
static_assert(sizeof(ActionInput) == 0x28, "ActionInput size");

struct ActionOutput
{
    BSFixedString animEvent;  // 00
    BSFixedString targetAnimEvent;  // 08
    std::int32_t result;  // 10
    std::uint32_t pad14;  // 14
    TESIdleForm* sequence;  // 18
    const TESIdleForm* animObjIdle;  // 20
    std::uint32_t sequenceIndex;  // 28
    std::uint32_t pad2C;  // 2C
};
static_assert(sizeof(ActionOutput) == 0x30, "ActionOutput size");

class BGSActionData : public ActionInput, public ActionOutput
{
public:
    BGSActionData();
    ~BGSActionData() override {}  // 00
    virtual BGSActionData* Clone() const;  // 04
    virtual bool Process();  // 05

    std::uint32_t flags;  // 58
    std::uint32_t pad5C;  // 5C
};
static_assert(sizeof(BGSActionData) == 0x60, "BGSActionData size");
