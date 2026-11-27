// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x30fc40 TESWorldSpace::AttachPortalGraph
#include "TESWorldSpace_30fc40.h"

void TESWorldSpace::AttachPortalGraph()
{
    if (multiBoundNode)
        portalRoot->SetAt2(8, multiBoundNode);
    if (portalSharedNode)
        portalRoot->SetAt2(9, portalSharedNode);
}
