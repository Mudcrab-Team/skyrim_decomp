// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6f5e40 ActorProcess::Function6f5e40
// Adapted bodies: none
#include "ActorProcess_6f5e40.h"

void ActorProcess::Function6f5e40(float value)
{
    if (unk10) {
        float b = unk10->unk2AC;
        float a = unk10->unk2A4;
        unk10->unk2A4 = (a < value) ? value : a;
        unk10->unk2AC = (value < b) ? b : value;
    }
}
