// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj27d090::Function27d090, treated as adapted: shaped like TESBipedModelForm::GetWorldModel in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesbipedmodelform.cpp:218
// SPDX-License-Identifier: CC0-1.0
// 0x27d090 Obj27d090::Function27d090
#include "Obj27d090.h"

// Returns the model path for the requested sex index, falling back from 1 to 0 if empty.
const char* Obj27d090::Function27d090(std::int32_t a_index)
{
    if (!ModelSlot27d090::HasModelPath(&models[a_index].modelPath) && a_index == 1) {
        a_index = 0;
    }
    return models[a_index].GetModelPath();
}
