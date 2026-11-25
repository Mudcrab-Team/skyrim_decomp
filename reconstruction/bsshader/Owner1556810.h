// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x15666e0 (bsshader/BSUtilityShader): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RestoreMaterial name source: powerof3/CommonLibSSE@654e55f, GPL-3.0. Only the declared name is taken; the body is written here.
// BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function1556810, Owner1556810: GUESS(low) STANDIN
// BSShader, unknown90: GUESS(low) STANDIN
#pragma once
#include "BSUtilityShader.h"

class Owner1556810 : public BSShader
{
public:
    virtual void RestoreMaterial(const BSShaderMaterial* a_material);
    bool Function1556810(void* a_arg);

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown90[0x8];  // 90
};
static_assert(sizeof(Owner1556810) == 0x98, "Owner1556810 size");
