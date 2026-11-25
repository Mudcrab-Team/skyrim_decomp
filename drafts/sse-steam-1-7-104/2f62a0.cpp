// Near miss: 3.5 alignment distance | control-flow
// Exposure detail: (community declarations and pinned-image observations).
// Source exposure: mixed
// Code origin: original; handwritten guarded static-object query
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x2f62a0 TESObjectREFR::Function2f62a0

#include "include/2f62a0/TESObjectREFR_2f62a0.h"

bool TESObjectREFR::Function2f62a0() const
{
    TESObjectSTAT* object = static_cast<TESObjectSTAT*>(data.objectReference);
    if (object && object->formType != FormType::Static) {
        object = nullptr;
    }
    if (object && object->QIsSkyObject()) {
        return true;
    }
    return false;
}
