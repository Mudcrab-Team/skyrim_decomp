// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSEffectShaderProperty, alpha, lastRenderPassState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetAlpha: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); both name it on BSShaderProperty, the base of this class
#pragma once

#include <cstdint>
#include <cstddef>

class BSEffectShaderProperty
{
public:
    void SetAlpha(float a_alpha);  // compared: 0x14e7f40

    std::uint8_t pad00[0x30];          // 00
    float        alpha;                // 30
    std::int32_t lastRenderPassState;  // 34
};
static_assert(offsetof(BSEffectShaderProperty, lastRenderPassState) == 0x34, "lastRenderPassState offset");
