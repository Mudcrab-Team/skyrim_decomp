// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESImageSpace::~TESImageSpace follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp:67
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESImageSpace.cpp:37
// TESImageSpace, TESImageSpace::~TESImageSpace, TESForm, TESForm::ClearData, TESForm::~TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk20: GUESS(low)
// TESImageSpace::TESImageSpace: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); emits the vftable.
#pragma once

#include <cstdint>
#include "declarations/TESForm.h"

class TESImageSpace : public TESForm
{
public:
    TESImageSpace();
    ~TESImageSpace() override;

    std::uint8_t unk20[0x50];
};
static_assert(sizeof(TESImageSpace) == 0x70, "image space layout");
