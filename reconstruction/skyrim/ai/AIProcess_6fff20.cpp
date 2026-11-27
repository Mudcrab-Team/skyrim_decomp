// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartShout: SYMBOLS(tesv-2013-map); candidate identity inferred from local behavior
// 0x6fff20 AIProcess::StartShout
#include "AIProcess_6fff20.h"

bool AIProcess::StartShout(TESShout* shout, unsigned int variation)
{
    if (high && shout && high->voiceState == 0 && variation <= 2) {
        high->currentShout = shout;
        high->currentShoutVariation = variation;
        high->voiceTimeElapsed = 0.0f;
        high->voiceState = 1;
        return true;
    }
    return false;
}
