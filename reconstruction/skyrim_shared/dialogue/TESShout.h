// Source exposure: mixed (pinned image listing and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations.
// Adapted bodies: none.
// TESShout, TESShout::Variation, ::variations, ::GetKnown, ::InitItemImpl, Variation::word, ::spell, ::recoveryTime, ::pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName, BGSMenuDisplayObject, BGSEquipType, TESDescription: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); each is a 0x10-byte component and only the base class and size are used
// TESWordOfPower: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the TESForm base is needed
// SpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declaration
// unk08: GUESS(low); the member of each component is not represented because no compared function reads it
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

class SpellItem;

class TESWordOfPower : public TESForm {
};

class TESFullName : public BaseFormComponent {
public:
    std::uint64_t unk08;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");

class BGSMenuDisplayObject : public BaseFormComponent {
public:
    std::uint64_t unk08;  // 08
};
static_assert(sizeof(BGSMenuDisplayObject) == 0x10, "BGSMenuDisplayObject size");

class BGSEquipType : public BaseFormComponent {
public:
    std::uint64_t unk08;  // 08
};
static_assert(sizeof(BGSEquipType) == 0x10, "BGSEquipType size");

class TESDescription : public BaseFormComponent {
public:
    std::uint64_t unk08;  // 08
};
static_assert(sizeof(TESDescription) == 0x10, "TESDescription size");

class TESShout : public TESForm, public TESFullName, public BGSMenuDisplayObject, public BGSEquipType, public TESDescription {
public:
    struct Variation {
        TESWordOfPower* word;          // 00
        SpellItem*      spell;         // 08
        float           recoveryTime;  // 10
        std::uint32_t   pad14;         // 14
    };
    static_assert(sizeof(Variation) == 0x18, "layout");

    void InitItemImpl() override;    // 13; compared: 0x387c90
    bool GetKnown() const override;  // 17

    Variation    variations[3];   // 60
};
static_assert(sizeof(TESShout) == 0xA8, "layout");
