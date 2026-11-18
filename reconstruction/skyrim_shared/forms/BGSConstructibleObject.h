// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSConstructibleObject::ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSCraftingSubobject, BGSCraftingSubobject::Slot00, Slot01, Slot02, sub20, unk08: GUESS(low); the names are invented, the layout follows the listing
// BGSResetList, BGSResetList::ResetList, list38: GUESS(low); the names are invented, ResetList is bound by address through bind-hints.json
#pragma once

#include <cstdint>
#include <cstddef>
#include "TESForm.h"

// BGSCraftingSubobject: GUESS(low); embedded at 0x20; its vtable slot 2 (offset 0x10) is called by ClearData
class BGSCraftingSubobject
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();  // slot 2, offset 0x10

    std::uint8_t unk08[0x10];  // 08
};
static_assert(sizeof(BGSCraftingSubobject) == 0x18, "BGSCraftingSubobject size");

// BGSResetList: GUESS(low); embedded at 0x38; ResetList is tail-called by ClearData
class BGSResetList
{
public:
    void ResetList();  // bound by address
};

class BGSConstructibleObject : public TESForm
{
public:
    virtual void ClearData();  // compared: 0x25de90

    BGSCraftingSubobject sub20;  // 20
    BGSResetList         list38;  // 38
};
