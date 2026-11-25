// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x252ba0 (skyrim_shared/world/TESRegionDataObjects): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Function14acfa0, Owner14acfa0: GUESS(low) STANDIN
// IsLoaded: GUESS(low) STANDIN
#pragma once
#include "TESRegionDataObjects.h"

class Owner14acfa0
{
public:
    virtual std::uint8_t IsLoaded() const;
    void Function14acfa0(std::uint8_t a_value);

    std::uint8_t pad08[0x8];  // 08
    const void* value10;      // 10
    unsigned char padTwin18[41];
    std::uint8_t value18;     // 18
};
