// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee0b30 NiAVObject::UpdateDownwardPass
// Adapted bodies: none
#include "NiAVObject_ee0b30.h"

void NiAVObject::UpdateDownwardPass(NiUpdateData& data, std::uint32_t)
{
    if (data.flags & 1) {
        for (NiTimeController* controller = controllers; controller; controller = controller->next) {
            controller->Update(data);
        }
    }
    UpdateWorldData(&data);
    UpdateWorldBound();
}
