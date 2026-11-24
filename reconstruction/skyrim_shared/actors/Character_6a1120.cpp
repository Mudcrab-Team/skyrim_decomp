// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x6a1120 Character::Function6a1120
// Adapted bodies: none
#include "Character_6a1120.h"

bool Character::Function6a1120() const
{
    bool result = false;
    if (CompareState(GetSitSleepState(), SIT_SLEEP_STATE::kNormal) != 0) {
        if (CompareState(GetSitSleepState(), SIT_SLEEP_STATE::kIsSitting) != 0) {
            if (CompareState(GetSitSleepState(), SIT_SLEEP_STATE::kIsSleeping) != 0) {
                result = true;
            }
        }
    }
    return result;
}
