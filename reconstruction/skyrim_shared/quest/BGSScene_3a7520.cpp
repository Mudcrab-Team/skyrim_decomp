// Source exposure: mixed (community-headers, binary-analysis).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a7520 BGSScene::HasActorId
// Adapted bodies: none
#include "BGSScene_3a7520.h"

bool BGSScene::HasActorId(std::uint32_t actorId)
{
    std::uint32_t index = 0xFFFFFFFF;
    for (std::uint32_t i = 0; i < actors.size && index == 0xFFFFFFFF; ++i) {
        if (actors.data[i] == actorId) {
            index = i;
        }
    }
    return index != 0xFFFFFFFF;
}
