// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect::CheckAge, finished, lifetime, age: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x5dbc30 ReferenceEffect::GetAttached
// 0x5d88c0 ReferenceEffect::Function5d88c0
// 0x5db6e0 ReferenceEffect::CheckAge
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

// Report whether the effect has finished or reached its lifetime.
bool ReferenceEffect::CheckAge() const
{
    if (finished || (lifetime >= 0.0f && !(lifetime >= age))) {
        return true;
    }
    return false;
}
