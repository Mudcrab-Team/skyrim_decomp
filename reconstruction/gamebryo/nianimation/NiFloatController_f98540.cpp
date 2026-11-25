// Source exposure: mixed (community declarations; community PDB names; pinned-image observations).
// Code origin: original; handwritten base processing and nullable payload dispatch
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf98540 NiFloatController::Functionf98540
// Adapted bodies: none
#include "NiFloatController_f98540.h"

void NiFloatController::Functionf98540(NiCloningProcess& cloning)
{
    NiTimeController::ProcessClone(cloning);
    if (data) {
        data->ProcessClone(cloning);
    }
}
