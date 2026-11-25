// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2caf00 TESObjectCELL::Function2caf00
// Adapted bodies: none.
#include "TESObjectCELL_2caf00.h"
#include <intrin.h>

// Replaces the loaded portal graph while preserving shared ownership.
void TESObjectCELL::Function2caf00(BSPortalGraph* graph)
{
    BSPortalGraph*& slot = loadedData->portalGraph;
    BSPortalGraph* previous = slot;
    if (previous != graph) {
        if (graph)
            // Shared ownership updates require atomic reference counting.
            _InterlockedIncrement(&graph->_refCount);
        slot = graph;
        // Shared ownership releases require atomic reference counting.
        if (previous && _InterlockedDecrement(&previous->_refCount) == 0)
            previous->DeleteThis();
    }
}
