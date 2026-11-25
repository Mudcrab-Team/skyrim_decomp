// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xcd69f0 (bsaudio/BSAudioListener): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Owner191be0: GUESS(low) STANDIN
// unknown08, unk2C, unk34, unk30, unk38: GUESS(low) STANDIN
#pragma once
#include "BSAudioListener.h"

class Owner191be0
{
public:
    virtual void Unk_05(const std::uint32_t* a_src);

    std::uint8_t  unknown08[0x8];  // 08
    std::uint32_t unk2C;            // 2C
    std::uint32_t unk30;            // 30
    std::uint32_t unk34;            // 34
    std::uint8_t  unk38[0x8];       // 38
};
static_assert(sizeof(Owner191be0) == 0x28, "Owner191be0 size");
