// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfedf50 BSCullingProcess::AppendNonAccum
#include "BSCullingProcess_fedf50.h"

#include <intrin.h>

inline void ObjectArray::Append(NiAVObject* object)
{
    unsigned int index;
    {
        ObjectArrayAllocator allocator(*this);
        index = count.AppendIndex(allocator, capacity, sizeof(object));
    }
    if (index != static_cast<unsigned int>(-1)) {
        data[index] = object;
        if (object) {
            // Other culling workers can retain the same object concurrently.
            _InterlockedIncrement(&object->refCount);
        }
    }
}

void BSCullingProcess::AppendNonAccum(NiAVObject* object)
{
    objectArray.Append(object);
}
