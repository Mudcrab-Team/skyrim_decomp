// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSOcclusionBox","rationale":"vtable owner and slot; method spelling invented","slot":38},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSOcclusionBox: EXE_RTTI
// Slot38: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Licence: these names come from powerof3/CommonLibSSE (GPL-3.0), so this file is GPL-3.0.
#pragma once
#include <cstdint>
// Slot38: GUESS(low); method name inferred from vtable owner and slot
class NiRTTI;

// BSOcclusionBox::IsOcclusionPlane, BSOcclusionBox::GetRTTI: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); GPL-3.0 applies to these names in this file; compared at RVA 0xfe8100, 0xfe8320
// NiRTTI_BSOcclusionBox: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the RTTI global at RVA 0x332e240, bound by hint
extern NiRTTI NiRTTI_BSOcclusionBox;

class BSOcclusionBox
{
public:
    virtual std::uint8_t Slot38() const;
    virtual bool IsOcclusionPlane() const;  // compared: 0xfe8100
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xfe8320
};
