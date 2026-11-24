// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOrderedNode, BSNiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSNiNode: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class BSNiNode
{
public:
    BSNiNode();
    virtual ~BSNiNode();
};

class BSOrderedNode : public BSNiNode
{
public:
    BSOrderedNode();
    ~BSOrderedNode() override {}

    char unk08[0x138];
};
static_assert(sizeof(BSOrderedNode) == 0x140, "BSOrderedNode size from the deleting destructor");
