// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Functionbb5530.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOffsetAnimationGenerator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Unk_18, Functionbb5530, unknown08, state42: GUESS(low)
#pragma once
#include <cstdint>

class BSOffsetAnimationGenerator
{
public:
    virtual std::uint8_t Unk_18() const;
    std::uint32_t Functionbb5530(std::uint8_t a_flags) const;

    std::uint8_t unknown08[0x3A];
    std::uint8_t state42;
};
