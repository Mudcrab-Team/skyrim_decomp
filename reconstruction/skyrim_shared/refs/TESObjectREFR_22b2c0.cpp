// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x22b2c0 TESObjectREFR::GetInventoryChanges
// Adapted bodies: none
#include "TESObjectREFR_22b2c0.h"

InventoryChanges* TESObjectREFR::GetInventoryChanges(FormType) const
{
    const auto reference = reinterpret_cast<std::uintptr_t>(this);
    if (reference) {
        const auto extraAddress = reference + 0x70;
        if (extraAddress) {
            return reinterpret_cast<ExtraDataList*>(extraAddress)->GetInventoryChanges();
        }
    }
    return nullptr;
}
