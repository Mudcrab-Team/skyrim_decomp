// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSOcclusionBox","rationale":"vtable owner and slot; method spelling invented","slot":38},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSOcclusionBox: EXE_RTTI
// Slot38: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xfe8110 BSOcclusionBox::Slot38
#include "BSOcclusionBox.h"
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
