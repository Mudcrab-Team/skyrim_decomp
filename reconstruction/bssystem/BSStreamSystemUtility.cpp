// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: names from a public source hint; the function body is written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x159ded0 BSStreamSystemUtility::Function159ded0
// Adapted bodies: none
// BSStreamSystemUtility::Function159ded0: GUESS(low)
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSStreamSystemUtility","rationale":"vtable owner and slot; method spelling invented","slot":4},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSStreamSystemUtility: EXE_RTTI
// Slot4: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "BSStreamSystemUtility.h"

void BSStreamSystemUtility::Function159ded0()
{
    field8 = Slot4();
}
// Slot4: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BSStreamSystemUtility::Slot4() const
{
    return 0x1;
}
