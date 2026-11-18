// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its
// BGSEquipSlot, BGSEquipSlot::InitializeData, BGSEquipSlot::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEquipSlot::parentSlots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares BSTArray<BGSEquipSlot*>, here an opaque 24-byte placeholder (offset 0x20 to 0x38)
// BGSEquipSlot::parentSlotsStorage: GUESS(low); placeholder bytes for parentSlots
#pragma once

#include <cstdint>

#include "TESForm.h"

class BGSEquipSlot : public TESForm {
public:
    void InitializeData() override;  // 04

    std::uint8_t  parentSlotsStorage[0x18];  // 20
    std::uint32_t flags;                     // 38
    std::uint32_t pad3C;                     // 3C
};
