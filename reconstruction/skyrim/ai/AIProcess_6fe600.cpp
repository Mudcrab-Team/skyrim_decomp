// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ForceFadeToNormal: SYMBOLS(tesv-2013-map); candidate identity inferred from local behavior
// 0x6fe600 AIProcess::ForceFadeToNormal
#include "AIProcess_6fe600.h"

void AIProcess::ForceFadeToNormal(Actor* actor)
{
    if (high && (high->fadeState == HighProcessData::kIn || high->fadeState == HighProcessData::kTeleportIn)) {
        high->fadeAlpha = 1.0f;
        high->fadeState = HighProcessData::kNormal;
        actor->vtable->UpdateAlpha(actor);
    }
}
