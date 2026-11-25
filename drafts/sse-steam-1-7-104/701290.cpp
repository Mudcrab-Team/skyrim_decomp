// Near miss: 1.16% | inline-set
// Exposure detail: (local target analysis and permitted name/layout references).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original body; permitted sibling inspected as a shape lead only.
// 0x701290 ActorProcess::GetCachedMovementSpeeds

#include "include/701290/ActorProcess_701290.h"

bool ActorProcess::GetCachedMovementSpeeds(Movement::MaxSpeeds& output) const
{
    bool available = high != nullptr;
    if (high) {
        output = high->currentMovementType.defaultData;
    }
    return available;
}
