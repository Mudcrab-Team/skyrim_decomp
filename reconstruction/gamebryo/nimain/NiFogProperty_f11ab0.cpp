// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf11e50 NiFogProperty::ReleaseDefault
// 0xf11ab0 NiFogProperty::CopyMembers
// Adapted bodies: none
#include "NiFogProperty_f11ab0.h"

extern NiFogProperty* gDefaultFogProperty;

void NiFogProperty::ReleaseDefault()
{
    if (auto* old = gDefaultFogProperty) {
        gDefaultFogProperty = nullptr;
        // Delete the property when the atomic decrement releases its final reference.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&old->_refCount), -1) == 1) {
            return old->DeleteThis();
        }
    }
}

void NiFogProperty::CopyMembers(NiFogProperty* dest)
{
    NiProperty::CopyMembers(dest);
    dest->fogFlags = fogFlags;
    dest->unknown34 = unknown34;
    dest->color38 = color38;
    dest->color44 = color44;
}
