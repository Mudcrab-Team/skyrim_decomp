// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartDeferredKill: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/AIProcess_MiddleHigh.cpp:1811
// Body adapted from the permitted sibling's deferred-kill state update.
// 0x7285a0 AIProcess::StartDeferredKill
#include "AIProcess_7285a0.h"

void AIProcess::StartDeferredKill(bool fromScript)
{
    if (middleHigh) {
        if (!middleHigh->deferredKillState)
            middleHigh->deferredKillState = 1;
        middleHigh->inDeferredKill |= fromScript;
        ResetDeferredKillTimer(deferredKillDuration);
    }
}
