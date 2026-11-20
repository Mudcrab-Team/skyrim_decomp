// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf80cb0 NiLookAtInterpolator::Collapse
// 0xf80dd0 NiLookAtInterpolator::ResolveDependencies
#include "NiLookAtInterpolator_f80cb0.h"

void NiLookAtInterpolator::Collapse()
{
    auto* slot = childInterpolators;
    std::size_t remaining = 3;
    do {
        if (*slot) {
            (*slot)->Collapse();
        }
        ++slot;
    } while (--remaining != 0);
}

bool NiLookAtInterpolator::ResolveDependencies(NiAVObjectPalette* palette)
{
    if (lookAt) {
        return true;
    }
    auto* resolved = palette->GetAVObject(targetName);
    if (resolved) {
        lookAt = resolved;
        return true;
    }
    return false;
}
