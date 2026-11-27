// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x421960 TESForm::GetTemperedFormSkillAdvanceAmount
// Adapted bodies: none
#include "TESForm_421960.h"

#include <cmath>

// Computes skill experience gained from tempering a form from a_oldHealth to a_newHealth.
float TESForm::GetTemperedFormSkillAdvanceAmount(float a_newHealth, float a_oldHealth) const
{
    std::int32_t goldValue = GetGoldValue();
    if (goldValue < 1) {
        goldValue = 1;
    }
    float baseXp = std::powf(static_cast<float>(goldValue), g_temperSkillExp) * g_temperSkillMult + g_temperSkillOffset;
    return baseXp * ((a_newHealth - a_oldHealth) * g_temperHealthMult);
}
