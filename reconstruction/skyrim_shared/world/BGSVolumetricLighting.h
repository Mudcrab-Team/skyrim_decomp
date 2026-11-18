// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSVolumetricLighting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSVolumetricLighting::~BGSVolumetricLighting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../forms/TESForm.h"

class BGSVolumetricLighting : public TESForm
{
public:
    BGSVolumetricLighting();
    void ClearData() override;  // 05
    virtual ~BGSVolumetricLighting();  // compared: 0x263d40 (scalar deleting destructor)

    // unknown20: GUESS(low); the padding to the size the sized operator delete receives
    std::uint8_t unknown20[0x30];  // 20
};
static_assert(sizeof(BGSVolumetricLighting) == 0x50, "BGSVolumetricLighting size");
