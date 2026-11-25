// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x700180 ActorProcess::Function700180
// Adapted bodies: none
#include "ActorProcess_700180.h"

void ActorProcess::Function700180(std::int32_t which, float value)
{
    HighProcessData* data = unk10;
    if (data) {
        switch (which) {
        case 0x18:
            data->word1C = value;
            break;
        case 0x19:
            data->word24 = value;
            break;
        case 0x1A:
            data->word20 = value;
            break;
        }
    }
}
