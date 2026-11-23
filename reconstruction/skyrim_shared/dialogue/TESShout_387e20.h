// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESShout, TESShout::FindLastFilledVariation, ShoutVariation, word, spell, recoveryTime: GUESS(low)
// variations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

struct ShoutVariation
{
    void* word;
    void* spell;
    float recoveryTime;
};

class TESShout
{
public:
    uint8_t unk00[0x60];
    ShoutVariation variations[3];

    int32_t FindLastFilledVariation();  // compared: 0x387e20
};
