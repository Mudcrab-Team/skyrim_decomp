// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Code origin: original reconstruction of the three added functions from the listings and the CrashLogger and FO4 names
// SPDX-License-Identifier: CC0-1.0
// 0x756c60 PlayerCharacter::IsActionInList
// 0x7559d0 PlayerCharacter::SetBusyActivatingTeleportDoor
// 0x7559b0 PlayerCharacter::QWarnToLeave
#include "PlayerCharacter_7559b0.h"

bool PlayerCharacter::IsActionInList(PLAYER_ACTION a_action) const
{
    return a_action < PLAYER_ACTION::kTotal && actionList[static_cast<int>(a_action)].word00 != 0x10;
}

void PlayerCharacter::SetBusyActivatingTeleportDoor()
{
    busyUntil = teleportClock + teleportDoorBusyTime;
}

bool PlayerCharacter::QWarnToLeave() const
{
    return !(busyUntil - teleportClock > 0.0f);
}
