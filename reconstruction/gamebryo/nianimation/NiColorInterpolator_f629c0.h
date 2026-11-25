// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiColorInterpolator, NiColorA, NiColorData, GetChannelPosed, colorValue, colorData, red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00, invalidColor: GUESS(low) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>

class NiColorData;
struct NiColorA { float red, green, blue, alpha; };
class NiColorInterpolator
{
public:
    bool GetChannelPosed(std::uint16_t channel) const;
    std::uint8_t unknown00[0x18];
    NiColorA colorValue;
    NiColorData* colorData;
};
static_assert(offsetof(NiColorInterpolator, colorValue) == 0x18, "color offset");
static_assert(offsetof(NiColorInterpolator, colorData) == 0x28, "color data offset");
extern const NiColorA invalidColor;
