// Near miss: 10.5 alignment distance | control-flow
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x5d16d0 MagicTarget::HasMagicEffect

#include "include/5d16d0/MagicTarget_5d16d0.h"

std::uint32_t MagicTarget::HasMagicEffect(EffectSetting* effect)
{
    auto* list = vtable->GetActiveEffectList(this);
    if (0 != list) {
    std::uint8_t found = static_cast<int>(0);
    auto* node = list->next || list->effect ? list : nullptr;
    while (node && !found) {
        if (node->effect && node->effect->GetBaseObject() == effect) {
            found = 1;
        }
        node = node->next;
    }
    return found;
}
        return false;
}
