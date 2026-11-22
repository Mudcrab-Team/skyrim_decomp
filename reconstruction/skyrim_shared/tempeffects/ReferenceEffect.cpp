// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function5d88c0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x5dbc30 ReferenceEffect::GetAttached
// 0x5d88c0 ReferenceEffect::Function5d88c0
#include "ReferenceEffect.h"

std::uint8_t ReferenceEffect::GetAttached() const
{
    return 0x1;
}

bool ReferenceEffect::Function5d88c0()
{
    if (controller) {
        return controller->Slot16();
    }
    return true;
}
