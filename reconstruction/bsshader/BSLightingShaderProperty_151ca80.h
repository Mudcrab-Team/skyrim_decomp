// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderProperty, BSLightingShaderProperty::AcceptsEffectData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); shader property flag word
#pragma once

#include <cstdint>
#include <cstddef>

class BSLightingShaderProperty
{
public:
    bool AcceptsEffectData() const;  // compared: 0x151ca80

    std::uint8_t unk00[0x38];
    std::uint64_t flags;
};
