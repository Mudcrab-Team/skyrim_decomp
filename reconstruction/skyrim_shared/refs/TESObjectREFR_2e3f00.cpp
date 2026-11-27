// Source exposure: mixed
// Code origin: original; local target observations and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e3f00 TESObjectREFR::Function2e3f00
// Adapted bodies: none
// Cookbook: 34
#include "TESObjectREFR_2e3f00.h"

bool TESObjectREFR::Function2e3f00() const
{
    bool result = IsWater();
    if (!result) {
        TESBoundObject* object = objectReference;
        if (object && (object->formType == 0x22 || object->formType == 0x24))
            result = object->QHasCurrents();
    }
    return result;
}
