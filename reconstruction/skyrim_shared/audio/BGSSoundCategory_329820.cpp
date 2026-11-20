// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x329820 BGSSoundCategory::Matches
// 0x329870 BGSSoundCategory::GetCategoryVolume
// 0x329920 BGSSoundCategory::GetCategoryFrequency
// 0x329a30 BGSSoundCategory::Function329a30
// 0x329a70 BGSSoundCategory::Function329a70
// 0x329aa0 BGSSoundCategory::Function329aa0
#include "BGSSoundCategory_329820.h"

// inheritedMultiplier, staticVolumeScale: GUESS(low)
extern const float inheritedMultiplier;
extern const float staticVolumeScale;

bool BGSSoundCategory::Matches(const BSISoundCategory* category) const
{
    if (static_cast<const BSISoundCategory*>(this) == category) {
        return true;
    }
    if (parentCategory && parentCategory->Matches(category)) {
        return true;
    }
    return false;
}

float BGSSoundCategory::GetCategoryVolume() const
{
    const auto inherited = !parentCategory ? inheritedMultiplier : parentCategory->GetCategoryVolume();
    return static_cast<float>(staticMult) * staticVolumeScale * volumeMult * inherited;
}

float BGSSoundCategory::GetCategoryFrequency() const
{
    if (!parentCategory) {
        return inheritedMultiplier * frequencyMult;
    }
    return parentCategory->GetCategoryFrequency() * frequencyMult;
}

bool BGSSoundCategory::Function329a30() const
{
    if ((categoryStateFlags & 1u) || (parentCategory && parentCategory->Function329a30())) {
        return true;
    }
    return false;
}

void BGSSoundCategory::Function329a70(bool enabled)
{
    const auto previous = categoryStateFlags;
    categoryStateFlags = enabled ? previous | 2u : previous & ~2u;
}

void BGSSoundCategory::Function329aa0(bool enabled)
{
    const auto previous = categoryStateFlags;
    categoryStateFlags = enabled ? previous | 1u : previous & ~1u;
}
