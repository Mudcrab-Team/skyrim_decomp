// Source exposure: mixed (local binary analysis and public names).
// 0x184c60 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraEnchantment: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraEnchantment
{
public:
    virtual std::uint32_t GetType() const;
    // ExtraEnchantment::Function184c60: GUESS(low); compared at RVA 0x184c60
    bool Function184c60(const ExtraEnchantment* a_other) const;

    std::uint8_t pad08[0x8];  // 08
    std::uint64_t m10;  // 10
    std::uint16_t m18;  // 18
    std::uint8_t m1A;  // 1A
};
