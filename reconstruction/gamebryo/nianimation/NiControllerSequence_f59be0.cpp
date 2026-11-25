// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten blend-entry loop.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf59be0 NiControllerSequence::Functionf59be0
// Adapted bodies: none.
#include "NiControllerSequence_f59be0.h"

void NiControllerSequence::Functionf59be0()
{
    for (std::uint32_t index = 0; index < arraySize; ++index) {
        InterpArrayItem& item = interpArray[index];
        if (item.blendInterp) {
            item.blendInterp->RemoveInterpolator(item.blendIdx);
        }
    }
}
