// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3d0480 TESQuest::SetKeepInstance
// Adapted bodies: none
#include "TESQuest_3d0480.h"

// Updates the keep-instance flag bit and marks change flag 2 if the value changed.
void TESQuest::SetKeepInstance(bool a_keep)
{
    bool current = ((questFlags >> 13) & 1) != 0;
    if (a_keep != current) {
        if (a_keep) {
            questFlags |= 0x2000u;
        } else {
            questFlags &= ~0x2000u;
        }
        AddChange(2);
    }
}
