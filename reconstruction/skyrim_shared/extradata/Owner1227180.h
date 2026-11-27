// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x18c300 (skyrim_shared/extradata/ExtraInteraction): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Function1227180, Owner1227180, interaction_target_1227180: GUESS(low) STANDIN
// GetType: GUESS(low) STANDIN
#pragma once
#include "ExtraInteraction.h"

class Owner1227180
{
public:
    virtual std::uint32_t GetType() const;
    void* Function1227180();

    // interaction is the pointer stored at the measured offset 0x10

    void* interaction;
};
static_assert(sizeof(Owner1227180) == 0x10, "Owner1227180 measured size");
