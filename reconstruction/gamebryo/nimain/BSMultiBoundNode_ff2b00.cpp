// Code origin: bodies written from the pinned image listing; declarations from the community headers.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0xff2b00 BSMultiBoundNode::RegisterStreamables
#include "BSMultiBoundNode_ff2b00.h"

// RegisterStreamables: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
bool BSMultiBoundNode::RegisterStreamables(NiStream& a_stream)
{
    if (!BSNiNode::RegisterStreamables(a_stream)) {
        return false;
    }
    multiBound->RegisterStreamables(a_stream);
    return true;
}
