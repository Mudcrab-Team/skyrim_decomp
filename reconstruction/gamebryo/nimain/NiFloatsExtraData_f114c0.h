// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original stand-in declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraData, size, value: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionf114c0, unknown00: GUESS(low); array-comparison helper inferred from observed accesses.
#pragma once

#include <cstdint>
#include <cstddef>

class NiFloatsExtraData
{
public:
    bool Functionf114c0(const NiFloatsExtraData* other) const;
    std::uint8_t unknown00[0x18];
    std::uint32_t size;
    float* value;
};
static_assert(offsetof(NiFloatsExtraData, value) == 0x20, "value offset");
