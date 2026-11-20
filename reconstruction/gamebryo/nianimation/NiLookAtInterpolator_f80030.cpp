// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf80030 NiLookAtInterpolator::RegisterStreamables
// 0xf80f30 NiLookAtInterpolator::GuaranteeTimeRange
// 0xf81060 NiLookAtInterpolator::SetTargetName
// Adapted bodies: none
#include "NiLookAtInterpolator_f80030.h"

void AssignFixedString(BSFixedString& dest, const BSFixedString& source);

bool NiLookAtInterpolator::RegisterStreamables(NiStream& stream)
{
    if (!NiInterpolator::RegisterStreamables(stream)) {
        return false;
    }
    for (std::uint32_t index = 0; index < 3; ++index) {
        auto* child = children[index];
        if (child && !child->RegisterStreamables(stream)) {
            return false;
        }
    }
    stream.RegisterFixedString(targetName);
    return true;
}

void NiLookAtInterpolator::GuaranteeTimeRange(float start, float end)
{
    auto* current = children;
    std::size_t remaining = 3;
    do {
        if (auto* child = *current) {
            child->GuaranteeTimeRange(start, end);
        }
        ++current;
    } while (--remaining != 0);
}

void NiLookAtInterpolator::SetTargetName(const BSFixedString& name)
{
    return AssignFixedString(targetName, name);
}
