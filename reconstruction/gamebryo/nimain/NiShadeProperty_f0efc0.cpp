// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf0efc0 NiShadeProperty::ReleaseDefault
// Adapted bodies: none
#include "NiShadeProperty_f0efc0.h"

extern NiShadeProperty* gDefaultShadeProperty;

void NiShadeProperty::ReleaseDefault()
{
    if (auto* old = gDefaultShadeProperty) {
        gDefaultShadeProperty = nullptr;
        // Delete the property when the atomic decrement releases its final reference.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&old->_refCount), -1) == 1) {
            return old->DeleteThis();
        }
    }
}
