// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x2240f0 GetObjectIndexInSceneGraph
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GlobalFunc.cpp:791
#include "GlobalFunc_2240f0.h"

int GetObjectIndexInSceneGraph(NiAVObject* apRoot, NiAVObject* apObject, bool abIgnoreDecals, bool abIgnoreSkinnedDecals)
{
    int index = 0;
    if (RecurseAndGetObjectIndexInSceneGraph(apRoot, apObject, index, abIgnoreDecals, abIgnoreSkinnedDecals))
        return index;
    return -1;
}
