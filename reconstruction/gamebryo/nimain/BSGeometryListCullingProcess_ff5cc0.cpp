// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xff5cc0 BSGeometryListCullingProcess::ReserveObjectArray
#include "BSGeometryListCullingProcess_ff5cc0.h"

inline void ObjectArray::Reserve(unsigned int requested)
{
    ObjectArrayAllocator allocator(*this);
    count.Reserve(allocator, capacity, requested, sizeof(NiAVObject*));
}

void BSGeometryListCullingProcess::ReserveObjectArray()
{
    objectArray.Reserve(32768);
}
