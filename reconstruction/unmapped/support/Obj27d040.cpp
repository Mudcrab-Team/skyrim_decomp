// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj27d040::Function27d040, treated as adapted: shaped like TESBipedModelForm::GetBipedModel and the same fallback in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesbipedmodelform.cpp:200
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:1092
// SPDX-License-Identifier: CC0-1.0
// 0x27d040 Obj27d040::Function27d040
#include "Obj27d040.h"

// Returns the model entry for the requested sex index, falling back from 1 to 0 if empty.
ModelSlot27d040* Obj27d040::Function27d040(std::int32_t a_index)
{
    if (!ModelSlot27d040::HasModelPath(&models[a_index].modelPath) && a_index == 1) {
        a_index = 0;
    }
    return &models[a_index];
}
