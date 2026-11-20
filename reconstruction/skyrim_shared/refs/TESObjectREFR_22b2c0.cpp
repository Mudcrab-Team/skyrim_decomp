// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x22b2c0 TESObjectREFR::GetInventoryChanges
// Adapted bodies: none
#include "TESObjectREFR_22b2c0.h"

InventoryChanges* TESObjectREFR::GetInventoryChanges(FormType) const
{
    // The target checks both the reference and the resulting list address.
    if (!this) {
        return nullptr;
    }
    auto* data = const_cast<ExtraDataList*>(&extraList);
    if (reinterpret_cast<std::uintptr_t>(data) != 0) {
        return data->GetInventoryChanges();
    }
    return nullptr;
}
