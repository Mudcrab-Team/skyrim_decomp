// Source exposure: mixed (community and permitted sibling names; local binary analysis).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSConstructibleObject, TESFurniture, BGSKeyword, BGSKeywordForm, TESCondition, PlayerCharacter, HasKeyword, head, conditions, benchKeyword, IsTrue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CanBeCreatedOnWorkbench: SIBLING(fo4-private@1b765c70, author-permission)
// BGSKeywordForm, TESFurniture, TESCondition, PlayerCharacter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// prefix, keywordForm, unknownSlot0, unknownSlot1, unknownSlot2, unknownSlot3, singleton: GUESS(low); partial layout and singleton binding
#pragma once

#include <cstddef>

class BGSKeyword;
class PlayerCharacter
{
public:
    static PlayerCharacter* singleton;
};

class BGSKeywordForm
{
public:
    virtual void unknownSlot0();
    virtual void unknownSlot1();
    virtual void unknownSlot2();
    virtual void unknownSlot3();
    virtual bool HasKeyword(const BGSKeyword*) const;
};

class TESFurniture
{
public:
    char prefix[0x90];
    BGSKeywordForm keywordForm;
};

class TESCondition
{
public:
    bool IsTrue(PlayerCharacter*, PlayerCharacter*) const;
    void* head;
};

class BGSConstructibleObject
{
public:
    bool CanBeCreatedOnWorkbench(TESFurniture*, bool) const;
    char prefix[0x38];
    TESCondition conditions;
    void* createdItem;
    BGSKeyword* benchKeyword;
};
// createdItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
static_assert(offsetof(BGSConstructibleObject, conditions) == 0x38, "condition member offset");
static_assert(offsetof(BGSConstructibleObject, benchKeyword) == 0x48, "workbench keyword offset");
static_assert(offsetof(TESFurniture, keywordForm) == 0x90, "keyword component offset");
