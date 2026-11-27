// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiNode: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class NiNode
{
public:
    NiNode();
    virtual ~NiNode();
};

class BSTempNode : public NiNode
{
public:
    BSTempNode();
    ~BSTempNode() override {}

    char unk08[0x128];
};
static_assert(sizeof(BSTempNode) == 0x130, "BSTempNode size from the deleting destructor");
