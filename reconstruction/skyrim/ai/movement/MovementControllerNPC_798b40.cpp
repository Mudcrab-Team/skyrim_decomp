// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x798b40 MovementControllerNPC::Function798b40
#include "MovementControllerNPC_798b40.h"
void MovementControllerNPC::Function798b40()
{
    if (motionDrivenControl.Unk_06())
        return motionDrivenControl.Unk_04();
    const bool result = motionDrivenControl.Unk_07();
    if (result) {
        if (motionDrivenControl.Unk_08())
            return motionDrivenControl.Unk_05();
        return motionDrivenControl.Unk_03();
    }
    return;
}
