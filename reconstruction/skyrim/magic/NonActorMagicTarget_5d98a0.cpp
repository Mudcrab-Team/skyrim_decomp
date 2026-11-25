// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below; callees checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/NonActorMagicTarget.cpp:49
// 0x5d98a0 NonActorMagicTarget::AddTarget
#include "NonActorMagicTarget_5d98a0.h"

// A freshly added effect on a non-actor target is brought up to date with a full step.
bool NonActorMagicTarget::AddTarget(AddTargetData& a_targetData)
{
    bool added = MagicTarget::AddTarget(a_targetData);
    if (added) {
        MagicTarget::UpdateTarget(1.0f);
    }
    return added;
}
