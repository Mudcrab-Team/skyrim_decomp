// Source exposure: mixed (local binary analysis and public names).
// 0x184c30 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraPoison: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraPoison
{
public:
    virtual std::uint32_t GetType() const;
    // Function184c30: GUESS(low); true when either compared field differs.
    bool Function184c30(const ExtraPoison* a_other) const;

    // poisonSource, poisonCount: GUESS(low); the pointer and dword the compared routine compares.
    std::uint8_t  pad08[0x8];      // 08
    void*         poisonSource;    // 10
    std::uint32_t poisonCount;     // 18
};
