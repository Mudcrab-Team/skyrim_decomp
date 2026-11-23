// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Slot8 is synthesized from the bounded leaf template; Function1e6030 is original from the listing.
// PlayerCharacter: EXE_RTTI
// Slot8, Function1e6030: GUESS(low)
// member, padding, flags10: GUESS(low); storage names invented for the measured member offset
// 0x75c2b0 PlayerCharacter::Slot8
// Code origin: original; Slot8 from template and Function1e6030 from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1e6030 PlayerCharacter::Function1e6030
// 0x75d390 PlayerCharacter::Function75d390
// Code origin: Function75d390 original reconstruction from the pinned listing and community declarations (names only); no adapted body
#include "PlayerCharacter.h"
// Slot8: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t PlayerCharacter::Slot8() const
{
    return 0x1;
}

void PlayerCharacter::Function1e6030(bool a_set)
{
    if (a_set) {
        flags10 |= 0x10;
    } else {
        flags10 &= ~0x10u;
    }
}

void PlayerCharacter::Function75d390()
{
    if (g_playerCharacterManager->unknown160 <= 0)
        return;
    if (sleepSeconds != 0)
        return;
    Function5d2080(&magicTarget, 0.0f);
}
