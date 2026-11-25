// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original body; reduced declarations adapted from CommonLibSSE-NG, no copied bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGeometry, NiProperty, properties, DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Declaration sources: include/RE/B/BSGeometry.h and include/RE/N/NiRefObject.h; reduced accessed layout.
// SetProperty, refCount, opaqueBase: GUESS(low); property ownership setter and inherited counter inferred from local observations.
// Target: sse-steam-1-7-104, RVA 0x26d430; image hash is pinned in builds/target.json.
// AI assistance: gpt-6.1-sol; 2026-11-25. Confidence: medium; independent acceptance pending.
// 0x26d430 BSGeometry::SetProperty
#include "BSGeometry_26d430.h"

#include <intrin.h>

void BSGeometry::SetProperty(NiProperty* a_property)
{
    NiProperty* old = properties[0];
    if (old != a_property) {
        if (a_property) {
            // Ownership crosses threads, so the reference count changes atomically.
            _InterlockedIncrement(&a_property->refCount);
        }
        properties[0] = a_property;
        if (old) {
            // Ownership crosses threads, so the reference count changes atomically.
            if (_InterlockedExchangeAdd(&old->refCount, -1) == 1) {
                old->DeleteThis();
            }
        }
    }
}
