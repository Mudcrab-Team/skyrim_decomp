// Source exposure: mixed (local binary analysis and public names).
// 0x1810d0 compared function
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraTeleport: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Function191fe0: GUESS(low); helper tail-called with the two stored pointers
void Function191fe0(void* a_first, void* a_second);

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraTeleport
{
public:
    virtual std::uint32_t GetType() const;
    // ExtraTeleport::Function1810d0: GUESS(low); tail-calls a helper with this and the argument's stored pointers
    void Function1810d0(ExtraTeleport* a_other);

    std::uint8_t pad[0x8];  // 08
    void* member10;  // 10
};
