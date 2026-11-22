// Source exposure: mixed (local binary analysis and public names).
// 0x18b200 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraFlags: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraFlags
{
public:
    virtual std::uint32_t GetType() const;
    // Function18b200: GUESS(low); forwards the flag array and a count to a helper.
    bool Function18b200(ExtraFlags* a_other);

    // flags: GUESS(low); the four-byte flag array the compared body passes by address.
    std::uint8_t pad08[0x8];   // 08
    std::uint8_t flags[0x4];   // 10
};
