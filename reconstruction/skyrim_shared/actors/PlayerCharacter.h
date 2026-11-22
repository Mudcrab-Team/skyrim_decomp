// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding, Function1e6030, flags10: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot8: GUESS(low); method name inferred from vtable owner and slot
class PlayerCharacter
{
public:
    virtual std::uint8_t Slot8() const;
    void Function1e6030(bool a_set);

    std::uint32_t pad08;    // 08
    std::uint32_t pad0C;    // 0C
    std::uint32_t flags10;  // 10
};
