// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1d3620 BGSDestructibleObjectForm::GetModelSwap
// Adapted bodies: BGSDestructibleObjectForm::GetModelSwap from fo4-private@1b765c70 src/Shared/FormComponents/BGSDestructibleObjectForm.cpp:144 (see the header)
#include "BGSDestructibleObjectForm_1d3620.h"

TESModel* BGSDestructibleObjectForm::GetModelSwap(TESForm* a_form, int a_modelSwapIndex)
{
    BGSDestructibleObjectForm* form = GetDestructionForm(a_form);
    if (form && a_modelSwapIndex != -1 && form->data && a_modelSwapIndex < form->data->numStages)
        return form->data->stages[a_modelSwapIndex]->replacementModel;
    return nullptr;
}
