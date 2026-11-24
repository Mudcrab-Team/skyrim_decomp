// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x18c300 (skyrim_shared/extradata/ExtraInteraction): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Functionca4cf0, Ownerca4cf0, interaction_target_ca4cf0: GUESS(low) STANDIN
// GetType: GUESS(low) STANDIN
#pragma once
#include "ExtraInteraction.h"

class Ownerca4cf0
{
public:
    virtual std::uint32_t GetType() const;
    void* Functionca4cf0();

    // interaction is the pointer stored at the measured offset 0x10
    std::uint8_t padding08[0x20];
    void* interaction;
};
static_assert(sizeof(Ownerca4cf0) == 0x30, "Ownerca4cf0 measured size");
