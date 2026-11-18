// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Hazard: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObjectREFR: STANDIN EXE_RTTI
// Hazard::Unk_A3, Hazard::OnAddCellPerformQueueReference, Hazard::IsPermanent: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// TESObjectCELL: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../forms/TESForm.h"

class TESObjectCELL;

class TESObjectREFR : public TESForm
{
public:
};

class Hazard : public TESObjectREFR
{
public:
    void Unk_A3();  // compared: 0x7ee090
    virtual bool OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const;  // compared: 0x7ee9c0
    bool IsPermanent() const;  // compared: 0x7ee8d0
};
