// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x75c2b0 PlayerCharacter::Slot8
#include "PlayerCharacter.h"
// Slot8: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t PlayerCharacter::Slot8() const
{
    return 0x1;
}
