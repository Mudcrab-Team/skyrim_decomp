// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1e5f50 (skyrim_shared/refs/TESObjectREFR_1e5f50): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm::formFlags, TESForm::AddChange: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class models TESForm here, slot 0x0A
// Function1e6590, Owner1e6590: GUESS(low) STANDIN
#pragma once
#include "TESObjectREFR_1e5f50.h"

class Owner1e6590
{
public:
    virtual ~Owner1e6590();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual bool AddChange(std::uint32_t a_changeFlags);  // 0A

    void Function1e6590(bool a_set);

    unsigned char pad08[8];
    std::uint32_t formFlags;  // 10
};
