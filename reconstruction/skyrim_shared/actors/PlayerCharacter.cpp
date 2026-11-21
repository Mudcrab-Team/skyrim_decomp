// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction from the pinned listing and community declarations (names only); no adapted body.
// Adapted bodies: none.
// PlayerCharacter, Slot8: GUESS(low); vtable owner and slot; method spelling invented.
// PlayerCharacter::Slot8: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75c2b0 PlayerCharacter::Slot8
#include "PlayerCharacter.h"

std::uint8_t PlayerCharacter::Slot8() const
{
    return 0x1;
}

// 0x75d390 PlayerCharacter::Function75d390
void PlayerCharacter::Function75d390()
{
    if (g_playerCharacterManager->unknown160 <= 0)
        return;
    if (sleepSeconds != 0)
        return;
    Function5d2080(&magicTarget, 0.0f);
}
