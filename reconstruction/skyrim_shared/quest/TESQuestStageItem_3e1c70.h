// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESQuestStage.cpp:214
// TESQuestStageItem, TESQuestStageItem::SetConditions, TESQuestStageItem::objConditions, TESCondition, TESCondition::Copy: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
// TESCondition::head: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// apUnused: GUESS(low); the second Copy argument is unused by the listing
#pragma once

class TESCondition
{
public:
    TESCondition();
    ~TESCondition();
    void Copy(TESCondition* apSource, void* apUnused);

    void* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");

class TESQuestStageItem
{
public:
    void SetConditions(TESCondition* apCond);

    TESCondition objConditions;  // 00
};
