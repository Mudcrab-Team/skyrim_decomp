// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0x151e2e0 BSShaderAccumulator::StartAccumulating
// 0x151ef00 BSShaderAccumulator::FinishAccumulatingPostResolveDepth
// Adapted bodies: none
#include "BSShaderAccumulator.h"

void BSShaderAccumulator::StartAccumulating(NiCamera* a_camera)
{
    camera = a_camera;
}

void BSShaderAccumulator::FinishAccumulatingPostResolveDepth(std::uint32_t flags)
{
    if (unk150 == 0) {
        PrepareDepth();
    }
    NiAccumulator::FinishAccumulating(flags);
}
