// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x21fe10 Function21fe10
// Adapted bodies: none
#include "FreeFunction_21fe10.h"

// Updates matching entries' flag byte and recomputes the OR of all entry flags.
void Function21fe10(FlagOwner21fe10* a_owner, std::uint16_t a_id, std::uint8_t a_value)
{
    a_owner->anyFlag = 0;
    for (std::uint32_t i = 0; i < a_owner->count; ++i) {
        if (a_owner->entries[i].id == a_id) {
            a_owner->entries[i].flag = a_value;
        }
        a_owner->anyFlag |= a_owner->entries[i].flag;
    }
}
