// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x44dc60 (skyrim/ai/BGSPackageDataRefOLD): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BGSPackageDataRefOLD","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Function451070, Owner451070: GUESS(low) STANDIN
// Slot6, Owner451070::Function44dc60, value: GUESS(low) STANDIN
#pragma once
#include "BGSPackageDataRefOLD.h"

class Owner451070
{
public:
    virtual std::uint32_t Slot6() const;
    std::uint32_t* Function451070(std::uint32_t* a_out) const;

    std::uint8_t pad08[0x8];  // 08
    std::uint32_t value;  // 18
};

