// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSPortalGraph, RemoveAlwaysRenderChild, alwaysRenderChildren, NiAVObject and flags: CRASHLOGGER_PDB(59818@2026.10.24)
// ObjectReference and ObjectArray: GUESS(low)
#pragma once

#include "BSPortalGraph_fd9eb0.h"
#include <intrin.h>
#include <cstddef>
#include "BSPortalSharedNode_fe9c20.h"

struct ObjectReference {
    explicit ObjectReference(NiAVObject* value)
    {
        if (value) {
            // Retain the child while the graph owns a reference.
            _InterlockedIncrement(reinterpret_cast<volatile long*>(&value->_refCount));
        }
        object = value;
    }
    ~ObjectReference()
    {
        auto* old = object;
        if (old) {
            // Only the last owner disposes of the object.
            const unsigned int remaining = _InterlockedDecrement(reinterpret_cast<volatile long*>(&old->_refCount));
            if (remaining == 0) {
                old->DeleteThis();
            }
        }
    }
    NiAVObject* object;
};

static_assert(offsetof(struct BSPortalGraph, alwaysRenderChildren) == 0x58, "child array offset");
