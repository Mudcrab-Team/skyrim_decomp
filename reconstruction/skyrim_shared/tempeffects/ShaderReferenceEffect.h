// Source exposure: mixed (local binary analysis and public names).
// Code origin: written for this reconstruction from the listing; member layout guessed from the measured offset.
// Adapted bodies: none.
// ShaderReferenceEffect: EXE_RTTI
// GetStackable: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// flags, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetStackable: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ShaderReferenceEffect
{
public:
    virtual std::uint8_t GetStackable() const;
    bool Function5e2320() const;

    std::uint8_t unk08[0x128];
    std::uint32_t flags;
};
