// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x44dc60 BGSPackageDataRefOLD::Function44dc60
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BGSPackageDataRefOLD","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSPackageDataRefOLD: EXE_RTTI
// Slot6: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "BGSPackageDataRefOLD.h"
// Slot6: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t BGSPackageDataRefOLD::Slot6() const
{
    return 0x1;
}

std::uint32_t* BGSPackageDataRefOLD::Function44dc60(std::uint32_t* a_out) const
{
    *a_out = value;
    return a_out;
}
