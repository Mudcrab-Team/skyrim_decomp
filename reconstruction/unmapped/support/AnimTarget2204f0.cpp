// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr2204f0::Reset and RefObject2204f0::DecRefCount, treated as adapted: shaped like NiPointer::reset and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/N/NiRefObject.cpp:28, MIT); AnimTarget2204f0::RefreshTargets also shaped like the target refresh loop in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:2753
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2204f0 AnimTarget2204f0::RefreshTargets
#include "AnimTarget2204f0.h"

// Re-resolve the cached root node and clear slots whose target node is missing.
void AnimTarget2204f0::RefreshTargets()
{
    SceneNode2204f0* root = holder->root;
    if (rootNode)
    {
        rootNode = root->GetObjectByName(&rootName);
    }
    for (std::uint32_t i = 0; i < count; ++i)
    {
        TargetEntry2204f0& entry = entries[i];
        if (!entry.name || !root->GetObjectByName(&entry.name))
        {
            slots[i].refObj.Reset();
            slots[i].ptr10 = nullptr;
            slots[i].flag18 = gDefaultFlag2204f0;
        }
    }
}
