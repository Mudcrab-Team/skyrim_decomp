// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x1813e0 (skyrim_shared/extradata/ExtraOwnership): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Owner181430: GUESS(low) STANDIN
// GetType, field8, owner: GUESS(low) STANDIN
#pragma once
#include "ExtraOwnership.h"

class Owner181430
{
public:
    virtual std::uint32_t GetType() const;
    Owner181430(ExtraOwnerData* a_owner);

    void*          field8;  // 08
    ExtraOwnerData* owner;  // 10
};

