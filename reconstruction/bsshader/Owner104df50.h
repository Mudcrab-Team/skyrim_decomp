// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original declarations reconstructed from the pinned image and labelled community types. Stamped as a twin of matched 0x154af70 (bsshader/BSLightingShader): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Function104df50, Owner104df50: GUESS(low) STANDIN
// BSShader, unknown90: GUESS(low) STANDIN
#pragma once
#include "BSLightingShader.h"

class Owner104df50 : public BSShader
{
public:
    static std::uint32_t GetVertexTechnique(std::uint32_t a_technique);
    void Function104df50();
    bool Function1547660(void* a_arg);

    std::uint8_t unknown90[0xc650];  // 90
    std::uint32_t counterC8;  // C8
    std::uint8_t unknownCC[0x2C];  // CC
};
static_assert(sizeof(Owner104df50) == 0xc710, "Owner104df50 size");
