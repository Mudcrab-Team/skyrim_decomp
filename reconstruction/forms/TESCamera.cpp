// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); body written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x558e10 TESCamera::GetNode
#include "TESCamera.h"

bool TESCamera::GetNode(NiPointer<NiNode>& a_out)
{
    a_out = cameraRoot;
    return a_out.pointer != nullptr;
}
