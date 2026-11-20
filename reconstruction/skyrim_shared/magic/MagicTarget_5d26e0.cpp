// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x5d26e0 MagicTarget::GetOwnerActor
#include "MagicTarget_5d26e0.h"

Actor* MagicTarget::GetOwnerActor()
{
    if (MagicTargetIsActor()) {
        return reinterpret_cast<Actor*>(reinterpret_cast<char*>(this) - 0xa0);
    }
    return nullptr;
}
