// Source exposure: mixed (local binary analysis and public names).
// 0x182a00 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraEnableStateParent: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraEnableStateParent
{
public:
    virtual std::uint32_t GetType() const;
    bool Function182a00(const ExtraEnableStateParent* a_other) const;  // compared: 0x182a00

    std::uint8_t pad08[8];  // 08
    std::uint8_t flag10;  // 10
    std::uint8_t pad11[3];  // 11
    std::uint32_t value14;  // 14
};
