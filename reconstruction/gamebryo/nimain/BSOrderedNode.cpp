// Code origin: hand-written from the local listings; names and declarations from the community header named in BSOrderedNode.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x1570700 BSOrderedNode::OnVisible
#include <intrin.h>
#include "BSOrderedNode.h"

// NiNode::OnVisible as called with the culling process and the visit index taken from the process counter.
// BSOrderedNode::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiNodeOnVisibleIndexed: STANDIN GUESS(low); the target passes a third argument, called at address 0xee2cc0
void NiNodeOnVisibleIndexed(NiNode* a_node, NiCullingProcess& a_process, int a_visitIndex);

// NiNodeRegisterStreamables: STANDIN GUESS(low); the target tests the low byte of the result, so the callee at address 0xee1650 is declared with a byte result
char NiNodeRegisterStreamables(NiNode* a_node, NiStream& a_stream);

// The culling process is a BSCullingProcess; declared complete only in this unit, with just the counter it reads.
// NiCullingProcess, BSCullingProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); sizes 0x128 and 0x301F8 as NG
// NiCullingProcess::~NiCullingProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSCullingProcess::unk301F0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSCullingProcess::unk301F0: OBSERVED; NG types it as 64 bits, the listing increments the low 32 bits atomically
// NiCullingProcess::unk008, BSCullingProcess::unk128, BSCullingProcess::unk301F4: GUESS(low); regions this unit never touches
class NiCullingProcess
{
public:
    virtual ~NiCullingProcess();

    std::uint8_t unk008[0x120];  // 008
};
static_assert(sizeof(NiCullingProcess) == 0x128, "NiCullingProcess size");

class BSCullingProcess : public NiCullingProcess
{
public:
    std::uint8_t unk128[0x301F0 - 0x128];  // 00128
    long unk301F0;                         // 301F0
    std::uint32_t unk301F4;                // 301F4
};
static_assert(sizeof(BSCullingProcess) == 0x301F8, "BSCullingProcess size");

bool BSOrderedNode::RegisterStreamables(NiStream& a_stream)
{
    return NiNodeRegisterStreamables(this, a_stream) != 0;
}

// Takes the next visit index from the culling process and hands it to the node's visible pass.
// Differs from the CrashLogger PDB entry, which records the indexed three-argument form on another class; this is the one-argument virtual.
void BSOrderedNode::OnVisible(NiCullingProcess& a_process)
{
    BSCullingProcess& process = static_cast<BSCullingProcess&>(a_process);
    // The visit counter is shared between culling threads, so it is bumped atomically.
    int visitIndex = _InterlockedIncrement(&process.unk301F0);
    NiNodeOnVisibleIndexed(this, a_process, visitIndex);
}
