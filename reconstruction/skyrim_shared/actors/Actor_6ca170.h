// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a view of the process pointer only
// Actor::GetEquippedWeaponEnchantment: CRASHLOGGER_PDB(59818@2026.10.24); the hand flag is forwarded untouched to the callee, read from the call site
// Actor::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places it at 0xf0, this build reads 0xf8
// Actor::GetEquippedWeaponEntry InventoryEntryData::GetFirstExtraList ExtraListNode ExtraListNode::item ExtraListNode::next: GUESS(low); inline accessors and the head node of the entry's extra-list list
// AIProcess EnchantmentItem ExtraDataList TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryEntryData InventoryEntryData::object InventoryEntryData::extraLists: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0x00 and 0x08, NG types the list as BSSimpleList
// AIProcess::GetCurrentlyEquippedWeapon: CRASHLOGGER_PDB(59818@2026.10.24); callee at RVA 0x720660, the address suffix of the recorded name is dropped
// TESForm::GetEnchantment: CRASHLOGGER_PDB(59818@2026.10.24); callee at RVA 0x1e1fd0, the address suffix of the recorded name is dropped
#pragma once

#include <cstdint>
#include <cstddef>

class EnchantmentItem;
class ExtraDataList;

class TESForm
{
public:
    EnchantmentItem* GetEnchantment(ExtraDataList* a_extra);
};

struct ExtraListNode
{
    ExtraDataList* item;  // 0x00
    ExtraListNode* next;  // 0x08
};

struct InventoryEntryData
{
    TESForm* object;            // 0x00
    ExtraListNode* extraLists;  // 0x08

    ExtraDataList* GetFirstExtraList() const { return extraLists ? extraLists->item : nullptr; }
};

class AIProcess
{
public:
    InventoryEntryData* GetCurrentlyEquippedWeapon(bool a_leftHand);
};

class Actor
{
public:
    EnchantmentItem* GetEquippedWeaponEnchantment(bool a_leftHand);  // compared: 0x6ca170

    InventoryEntryData* GetEquippedWeaponEntry(bool a_leftHand) const
    {
        return currentProcess ? currentProcess->GetCurrentlyEquippedWeapon(a_leftHand) : nullptr;
    }

    std::uint8_t pad00[0xF8];
    AIProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xF8, "currentProcess");
