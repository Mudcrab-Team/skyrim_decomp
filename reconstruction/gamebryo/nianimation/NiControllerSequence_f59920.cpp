// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf59920 NiControllerSequence::InterpArrayItem::RegisterStreamables
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
#include "NiControllerSequence_f59920.h"

void NiControllerSequence::InterpArrayItem::RegisterStreamables(NiStream& stream)
{
    if (interpolator) {
        interpolator->RegisterStreamables(stream);
    }
    if (interpCtlr) {
        interpCtlr->RegisterStreamables(stream);
    }
}
