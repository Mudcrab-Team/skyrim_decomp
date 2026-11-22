// Source exposure: mixed (local binary analysis and public names).
// 0x447ad0 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BGSAIWorldLocation","rationale":"vtable owner and slot; method spelling invented","slot":16},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSAIWorldLocation: EXE_RTTI
// Slot16: GUESS(low)
// Function447ad0: GUESS(low)
// kNullHandle: GUESS(low); 32-bit global in .data, no community name
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot16: GUESS(low); method name inferred from vtable owner and slot
extern unsigned int kNullHandle;
class BGSAIWorldLocation
{
public:
    virtual std::uint8_t Slot16() const;
    unsigned int* Function447ad0(unsigned int* out) const;
};
