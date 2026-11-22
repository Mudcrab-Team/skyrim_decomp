// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xfe81e0 BSOcclusionBox::~BSOcclusionBox
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSOcclusionBox","rationale":"vtable owner and slot; method spelling invented","slot":38},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSOcclusionBox: EXE_RTTI
// Slot38: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "BSOcclusionBox.h"

#include <intrin.h>

// gOcclusionBoxCount: GUESS(low); global instance count decremented by the destructor
extern std::uint32_t gOcclusionBoxCount;

BSOcclusionBox::~BSOcclusionBox()
{
    _InterlockedDecrement(reinterpret_cast<volatile long*>(&gOcclusionBoxCount));
}

// Slot38: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BSOcclusionBox::Slot38() const
{
    return 0x1;
}

bool BSOcclusionBox::IsOcclusionPlane() const
{
    return false;
}

const NiRTTI* BSOcclusionBox::GetRTTI() const
{
    return &NiRTTI_BSOcclusionBox;
}
