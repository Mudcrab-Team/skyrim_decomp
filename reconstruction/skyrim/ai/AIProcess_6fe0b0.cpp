// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FadeOut: SYMBOLS(tesv-2013-map); candidate identity inferred from local behavior
// 0x6fe0b0 AIProcess::FadeOut
#include "AIProcess_6fe0b0.h"

void AIProcess::FadeOut(Actor*, TESObjectREFR* trigger, bool teleport)
{
    if (high && high->fadeState != HighProcessData::kOutDisable && high->fadeState != HighProcessData::kOutDelete) {
        high->fadeState = static_cast<HighProcessData::FADE_STATE>(2 * static_cast<unsigned int>(teleport) + 2);
        if (trigger) {
            high->fadeTrigger = trigger;
        }
        if (high->fadeAlpha <= 0.0f) {
            high->fadeAlpha = 1.0f;
        }
    }
}
