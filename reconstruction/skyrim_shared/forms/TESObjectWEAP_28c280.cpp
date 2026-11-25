// Source exposure: mixed (pinned community declarations; private target observations).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x28c280 TESObjectWEAP::Function28c280
// Adapted bodies: none.
#include "TESObjectWEAP_28c280.h"

const BSFixedString& TESObjectWEAP::Function28c280() const
{
    if ((weaponData.flags & 0x20) != 0 && embeddedNode._data != GetDefaultEmbeddedNode()._data)
        return embeddedNode;
    return defaultEmbeddedNode;
}
