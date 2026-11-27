// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38f9c0 BGSEquipSlot::sub_140331580
// Adapted bodies: none
#include "BGSEquipSlot_38f9c0.h"

// Checks whether a_other matches this equip slot or any of its parent slots recursively.
bool BGSEquipSlot::sub_140331580(const BGSEquipSlot* a_other) const
{
    bool found = false;
    if (a_other) {
        if (this == a_other) {
            return true;
        }
        std::uint32_t i = 0;
        const std::uint32_t count = parentSlots.size;
        while (!found && i < count) {
            found = parentSlots[i]->sub_140331580(a_other);
            ++i;
        }
    }
    return found;
}
