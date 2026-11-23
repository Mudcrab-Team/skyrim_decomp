// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraReflectedRefs::IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraReflectedRefs: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ExtraReflectedRefs
{
public:
    bool IsNotEqual(const ExtraReflectedRefs* other) const;  // compared: 0x1835f0

    std::uint8_t unk00[0x10];
    std::uint32_t* data;  // 0x10
    std::uint8_t unk18[0x8];
    std::uint32_t count;  // 0x20
};
