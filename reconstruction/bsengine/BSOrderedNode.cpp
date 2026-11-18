// Code origin: hand-written from the local listings; names and declarations from the community header named in BSOrderedNode.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x1570370 BSOrderedNode::RegisterStreamables
// 0x1570700 BSOrderedNode::OnVisible
#include <intrin.h>
#include "BSOrderedNode.h"

// NiNode::OnVisible as called with the culling process and the visit index taken from the process counter.
// BSOrderedNode::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiNodeOnVisibleIndexed: STANDIN GUESS(low); the target passes a third argument, called at address 0xee2cc0
void NiNodeOnVisibleIndexed(NiNode* a_node, NiCullingProcess& a_process, int a_visitIndex);

// NiNodeRegisterStreamables: STANDIN GUESS(low); the target tests the low byte of the result, so the callee at address 0xee1650 is declared with a byte result
char NiNodeRegisterStreamables(NiNode* a_node, NiStream& a_stream);

// The culling process is a BSCullingProcess; the community header names its member at this offset unk301F0.
// BSCullingProcess::unk301F0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
static const std::size_t kCullingVisitCounterOffset = 0x301F0;

bool BSOrderedNode::RegisterStreamables(NiStream& a_stream)
{
    return NiNodeRegisterStreamables(this, a_stream) != 0;
}

void BSOrderedNode::OnVisible(NiCullingProcess& a_process)
{
    volatile long* counter = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(&a_process) + kCullingVisitCounterOffset);
    // The compared function does a locked increment of the culling counter, so the intrinsic is needed.
    int visitIndex = _InterlockedIncrement(counter);
    NiNodeOnVisibleIndexed(this, a_process, visitIndex);
}
