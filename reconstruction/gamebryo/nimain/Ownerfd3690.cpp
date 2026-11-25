// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xf0cb90 (gamebryo/nimain/NiGeometry_f0cb90): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0xfd3690 Ownerfd3690::Functionfd3690
#include "Ownerfd3690.h"
#include <intrin.h>

// guess: same compiled code as matched 0xf0cb90 apart from relocated fields; its role here is not established.
void Ownerfd3690::Functionfd3690(NiRefObjectStandIn* a_obj)
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
