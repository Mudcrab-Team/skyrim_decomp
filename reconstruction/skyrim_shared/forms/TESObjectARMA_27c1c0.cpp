// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x27c1c0 TESObjectARMA::ClearData
// Adapted bodies: none.
#include "TESObjectARMA_27c1c0.h"

void TESObjectARMA::ClearData()
{
    bipedModels[0].ClearDataComponent();
    bipedModels[1].ClearDataComponent();
    bipedModel1stPersons[0].ClearDataComponent();
    bipedModel1stPersons[1].ClearDataComponent();
}
