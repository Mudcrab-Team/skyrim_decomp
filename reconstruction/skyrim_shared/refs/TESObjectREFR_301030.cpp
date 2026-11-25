// Source exposure: mixed (community declarations; pinned-image observations; permitted sibling names).
// Code origin: original; handwritten target-observation draft
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x301030 TESObjectREFR::Function301030
// Adapted bodies: none
// Cookbook: 0x301030 2
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "TESObjectREFR_301030.h"

// Remove saved extra state, including an optional payload, then clear its change flag.
void TESObjectREFR::Function301030()
{
    extraList.Function16e7e0();
    SavedExtraNode* extra = extraList.Function16fc10();
    if (extra) {
        if (extra->payload) {
            extra->payload->Function4b9630(this);
        }
        extraList.Function16fd20();
    }
    RemoveChange(0x20000);
}
