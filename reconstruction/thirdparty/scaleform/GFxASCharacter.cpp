// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xd35d50 GFxASCharacter::Functiond35d50
// Adapted bodies: none
#include "GFxASCharacter.h"

void GFxASCharacter::Functiond35d50()
{
    // Clears the two character flags kept in bits 2 and 3.
    unk96 &= ~0x000C;
}
