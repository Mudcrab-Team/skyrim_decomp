// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Functionbb5530.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xbb4d50 BSOffsetAnimationGenerator::Unk_18
// 0xbb5530 BSOffsetAnimationGenerator::Functionbb5530
#include "BSOffsetAnimationGenerator.h"

std::uint8_t BSOffsetAnimationGenerator::Unk_18() const
{
    return 0x1;
}

std::uint32_t BSOffsetAnimationGenerator::Functionbb5530(std::uint8_t a_flags) const
{
    if (state42 == 2 || (a_flags & 1u) != 0u) {
        return 1u;
    }
    return 2u;
}
