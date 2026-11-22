// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: bodies written from the pinned image listing; class name from image RTTI
// 0x80a2f0 CombatAimController::Function80a2f0
// 0x80a280 CombatAimController::Function80a280
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"CombatAimController","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// CombatAimController: EXE_RTTI
// Slot6: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "CombatAimController.h"
// Slot6: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t CombatAimController::Slot6() const
{
    return 0x1;
}

void CombatAimController::Function80a280()
{
    flags3C &= ~1u;
}

void CombatAimController::Function80a2f0()
{
    aimValue = gAimDefault;
    aimCount = 0;
}
