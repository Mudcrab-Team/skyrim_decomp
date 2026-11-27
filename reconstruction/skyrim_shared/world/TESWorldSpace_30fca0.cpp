// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x30fca0 TESWorldSpace::DetachPortalGraph
#include "TESWorldSpace_30fca0.h"

void TESWorldSpace::DetachPortalGraph()
{
    if (multiBoundNode)
        portalRoot->DetachChild2(multiBoundNode);
    if (portalSharedNode)
        portalRoot->DetachChild2(portalSharedNode);
}
