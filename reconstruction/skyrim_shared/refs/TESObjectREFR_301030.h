// Source exposure: mixed (community declarations; pinned-image observations; permitted sibling names).
// Code origin: original; target observations with labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectREFR::extraList, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::Function301030, ExtraDataList::Function16e7e0, ExtraDataList::Function16fc10, ExtraDataList::Function16fd20: GUESS(low)
// SavedExtraPayload, SavedExtraPayload::Function4b9630, SavedExtraNode, SavedExtraNode::payload: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class SavedExtraPayload
{
public:
    void Function4b9630(TESObjectREFR* owner);
};

struct SavedExtraNode
{
    std::uint8_t reserved00[0x10];
    SavedExtraPayload* payload;
};

class ExtraDataList
{
public:
    void Function16e7e0();
    SavedExtraNode* Function16fc10();
    void Function16fd20();
    std::uint8_t reserved00[0x20];
};

class TESObjectREFR : public TESForm
{
public:
    void Function301030();
    std::uint8_t reserved20[0x50];
    ExtraDataList extraList;
};
static_assert(sizeof(TESForm) == 0x20, "form base extent");
static_assert(offsetof(SavedExtraNode, payload) == 0x10, "saved payload offset");
