// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x279ce0 TESObjectACTI::InitItemImpl
// Adapted bodies: none
#include "TESObjectACTI_279ce0.h"

// ApplyFormFlag: GUESS(low)
void ApplyFormFlag(TESForm* form, bool value);

// TestBit: GUESS(low)
static bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}

void TESObjectACTI::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        InitBaseComponents();
        return ApplyFormFlag(this, true);
    }
}
