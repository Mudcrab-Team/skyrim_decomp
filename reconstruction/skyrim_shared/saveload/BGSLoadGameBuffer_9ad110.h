// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer, Function9ad110, gLoadedByte, unk08: GUESS(low)
// GetVersion, LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares other parameters
#pragma once

#include <cstdint>
#include <cstddef>

// gLoadedByte: GUESS(low); a one-byte global filled from the save buffer
extern std::uint8_t gLoadedByte;

class BGSLoadGameBuffer
{
public:
    virtual ~BGSLoadGameBuffer();
    virtual std::uint8_t GetVersion();
    void LoadDataEndian(void* a_data, std::uint32_t a_size, std::uint32_t a_count);

    std::uint8_t unk08[0x20];

    void Function9ad110();  // compared: 0x9ad110
};
