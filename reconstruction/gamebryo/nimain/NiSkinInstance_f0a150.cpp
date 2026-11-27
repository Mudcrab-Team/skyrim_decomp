// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf0a150 NiSkinInstance::FindCommonAncestor
// Adapted bodies: none
#include "NiSkinInstance_f0a150.h"

NiAVObject* NiSkinInstance::FindCommonAncestor(NiAVObject* a_first, NiAVObject* a_second)
{
    for (NiAVObject* outer = a_second; outer; outer = outer->parent) {
        for (NiAVObject* inner = a_first; inner; inner = inner->parent) {
            if (inner == outer) {
                return inner;
            }
        }
    }
    return nullptr;
}
