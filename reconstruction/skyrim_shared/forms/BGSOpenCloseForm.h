// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSOpenCloseForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSOpenCloseForm::Unk_03, BGSOpenCloseForm::HandleClose, BGSOpenCloseForm::HandleOpen: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); Unk_03 returns bool in the listing, the community declaration says void
// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR;

class BGSOpenCloseForm
{
public:
    virtual bool Unk_03();  // compared: 0x267670
    virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator);  // compared: 0x2677e0
    virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator);  // compared: 0x2677f0
};
static_assert(sizeof(BGSOpenCloseForm) == 0x8, "BGSOpenCloseForm size");
