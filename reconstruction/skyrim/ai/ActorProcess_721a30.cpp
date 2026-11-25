// Source exposure: mixed (local target analysis and permitted name/layout references).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original ownership-release body; community lock implementation inspected.
// 0x721a30 ActorProcess::UnlockForDemandedAnimationSet
#include "ActorProcess_721a30.h"

void ActorProcess::UnlockForDemandedAnimationSet()
{
    if (middleHigh) {
        middleHigh->unk1E8.Unlock();
    }
}
