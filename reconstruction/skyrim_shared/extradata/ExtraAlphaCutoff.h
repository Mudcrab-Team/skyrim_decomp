// Source exposure: mixed (local binary analysis and public names).
// 0x18b130 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraAlphaCutoff: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraAlphaCutoff
{
public:
    virtual std::uint32_t GetType() const;
    bool Function18b130(const ExtraAlphaCutoff* a_other) const;  // compared: 0x18b130; GUESS(low)

    // padding08, field10, field11: GUESS(low); storage at the compared offsets
    std::uint8_t padding08[8];  // 08
    std::uint8_t field10;  // 10
    std::uint8_t field11;  // 11
};
