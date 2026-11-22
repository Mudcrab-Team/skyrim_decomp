// Source exposure: mixed (local binary analysis and public names).
// 0x159ded0 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSStreamSystemUtility","rationale":"vtable owner and slot; method spelling invented","slot":4},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSStreamSystemUtility: EXE_RTTI
// Slot4: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot4: GUESS(low); method name inferred from vtable owner and slot
class BSStreamSystemUtility
{
public:
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual std::uint8_t Slot4() const;
    // Function159ded0: STANDIN GUESS(low)
    void Function159ded0();  // compared: 0x159ded0
    std::uint8_t field8;
    std::uint8_t pad9[0x7];
};
