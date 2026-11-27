// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf0cb90 NiGeometry::SetSmartPointerMember
// Adapted bodies: none
#include <intrin.h>
#include "NiGeometry_f0cb90.h"

void NiGeometry::SetSmartPointerMember(NiRefObjectStandIn* a_obj)
{
    NiRefObjectStandIn* old = spData;
    if (old != a_obj) {
        if (a_obj) {
            // smart pointer refcounts are shared across threads, so atomic
            _InterlockedIncrement(&a_obj->m_uiRefCount);
        }
        spData = a_obj;
        // smart pointer refcounts are shared across threads, so atomic
        if (old && _InterlockedDecrement(&old->m_uiRefCount) == 0) {
            old->DeleteThis();
        }
    }
}
