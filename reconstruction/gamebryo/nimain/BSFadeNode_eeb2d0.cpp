// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:15
// SPDX-License-Identifier: CC0-1.0
// BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode::ExchangeControllerReference: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xeeb2d0 BSFadeNode::ExchangeControllerReference
#include "BSFadeNode_eeb2d0.h"

// Link the incoming controller ahead of the existing controller list.
void BSFadeNode::ExchangeControllerReference(NiTimeController* a_controller)
{
    if (a_controller) {
        a_controller->next = controllers._ptr;
        controllers = a_controller;
    }
}
