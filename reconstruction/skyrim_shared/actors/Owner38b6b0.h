// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function. Stamped as a twin of matched 0x38b250 (skyrim_shared/actors/BGSBodyPartData_38b250): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSBodyPart: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:50
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:58
// Owner38b6b0: GUESS(low) STANDIN
// unknown20, unknown80: GUESS(low) STANDIN
#pragma once
#include "BGSBodyPartData_38b250.h"

class Owner38b6b0 : public TESForm
{
public:
    void ClearData() override;

    std::uint8_t unknown20[0x30];
    BGSBodyPart* parts[6];
    std::uint8_t unknown80[8];
};
static_assert(sizeof(Owner38b6b0) == 0x88, "Owner38b6b0 size");
