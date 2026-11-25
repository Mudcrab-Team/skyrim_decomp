// Source exposure: mixed (local binary analysis, community declarations, permitted sibling study).
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// FadeIn: CRASHLOGGER_PDB(59818@2026.10.24)
// Sibling source: fo4-private@1b765c70 src/Game/AI/AIProcess_High.cpp:1964
// Original reconstruction with community field names; sibling supplied the signature lead.
// 0x6fe050 ActorProcess::FadeIn
#include "ActorProcess_6fe050.h"

// Begin a normal or teleport fade unless removal already owns the fade state.
void ActorProcess::FadeIn(Actor*, bool teleport)
{
    if (High_10 && static_cast<std::uint32_t>(High_10->fadeState) - 5 > 1) {
        High_10->fadeState = static_cast<HighProcessData::FADE_STATE>(1 + 2 * teleport);
        High_10->fadeTrigger = nullptr;
        if (!(1.0f > High_10->fadeAlpha)) {
            High_10->fadeAlpha = 0.0f;
        }
    }
}
