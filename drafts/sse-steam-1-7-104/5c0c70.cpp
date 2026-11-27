// Near miss: 4.0 alignment distance | control-flow
// code-byte-mismatch; best attempt 2, size 84/84, 51 matching bytes.
// Remaining floating-point load, subtraction, store order and register choice differ.
// Exposure detail: (local binary analysis, community declarations, permitted sibling study).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AdjustLight: SIBLING(fo4-private@1b765c70, author-permission) SYMBOLS(tesv-2013-map)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:396
// Original typed reconstruction; sibling used for method name and behavior lead.
// 0x5c0c70 ActorMagicCaster::AdjustLight

#include "include/5c0c70/ActorMagicCaster_5c0c70.h"

void ActorMagicCaster::AdjustLight(const NiPoint3& adjustment)
{
    if (light && light->light) {
        NiPoint3& position = light->light->world.translate;
        const float x = position.x;
        const float y = position.y;
        const float z = position.z;
        const float adjustedX = x - adjustment.x;
        position.x = adjustedX;
        const float adjustedY = y - adjustment.y;
        position.y = adjustedY;
        const float adjustedZ = z - adjustment.z;
        position.z = adjustedZ;
    }
}
