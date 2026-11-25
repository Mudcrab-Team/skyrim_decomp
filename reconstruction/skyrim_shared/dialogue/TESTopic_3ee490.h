// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESTopic, TESTopic::Function3ee490, TESTopicInfo, TESTopicInfo::Function3f2620: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESTopicInfo
{
public:
    void Function3f2620(std::uint16_t index);
};

class TESTopic
{
public:
    std::uint8_t unk00[0x48];
    TESTopicInfo** pTopicInfosA;
    std::uint32_t uiNumTopicInfos;
    void Function3ee490();
};
