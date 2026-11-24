// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSSoundDescriptorForm, Function32a830, SoundDescriptorInner, SoundDescriptorOut, GetFlag, inner, formID, unk00, unk08, unk0C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class SoundDescriptorInner
{
public:
    virtual void unk00();
    virtual std::uint8_t GetFlag() const;
};

struct SoundDescriptorOut
{
    std::uint8_t unk00[0xC];
    std::uint32_t formID;
};

// The method runs on a secondary base subobject of the form: the form's own id sits 0xC bytes before this.
class BGSSoundDescriptorForm
{
public:
    std::uint8_t unk00[8];
    SoundDescriptorInner* inner;

    std::uint8_t Function32a830(SoundDescriptorOut* a_out) const;  // compared: 0x32a830
};
