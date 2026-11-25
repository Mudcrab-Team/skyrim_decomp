// Source exposure: mixed (local binary analysis, community declarations, permitted sibling study).
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CheckForExpiredDetectionEvent: CRASHLOGGER_PDB(59818@2026.10.24)
// Sibling source: fo4-private@1b765c70 src/Game/AI/AIProcess_High.cpp:780
// Original cleanup body; sibling used as a behavior lead.
// 0x6f26e0 ActorProcess::CheckForExpiredDetectionEvent
#include "ActorProcess_6f26e0.h"

// Remove a retained detection event once its lifetime expires.
void ActorProcess::CheckForExpiredDetectionEvent()
{
    if (High_10) {
        DetectionEvent* event = High_10->actorsGeneratedDetectionEvent;
        if (event && currentAITime - event->timeStamp.timeStamp > detectionEventExpireTime) {
            High_10->actorsGeneratedDetectionEvent = nullptr;
            delete event;
        }
    }
}
