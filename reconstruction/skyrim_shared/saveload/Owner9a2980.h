// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x9ad110 (skyrim_shared/saveload/BGSLoadGameBuffer_9ad110): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function9a2980, Owner9a2980: GUESS(low) STANDIN
// unk08, GetVersion, LoadDataEndian: GUESS(low) STANDIN
#pragma once
#include "BGSLoadGameBuffer_9ad110.h"

class Owner9a2980
{
public:
    virtual ~Owner9a2980();
    virtual std::uint8_t GetVersion();
    void LoadDataEndian(void* a_data, std::uint32_t a_size, std::uint32_t a_count);

    std::uint8_t unk08[0x20];

    void Function9a2980();
};

