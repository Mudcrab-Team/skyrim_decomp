// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x421be0 ConstructibleObject::GetSkillAdvanceAmount
// Adapted bodies: none
#include "ConstructibleObject_421be0.h"

#include <cmath>

// Computes skill experience gained from crafting the constructible object.
float ConstructibleObject::GetSkillAdvanceAmount() const
{
    std::int32_t goldValue = createdItem ? createdItem->GetGoldValue() : 0;
    float baseValue = (goldValue > 0) ? static_cast<float>(goldValue * createdCount) : 1.0f;
    return std::powf(baseValue, g_constructSkillExp) * g_constructSkillMult + g_constructSkillOffset;
}
