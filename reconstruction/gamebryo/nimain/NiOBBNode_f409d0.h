// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// NiOBBNode: EXE_RTTI
// NiOBBNodeChild, NiOBBNode::unk88, NiOBBNode::unk90: GUESS(low); two owned child nodes; the second is deleted only with the first
#pragma once

class NiOBBNodeChild
{
public:
    virtual ~NiOBBNodeChild();
};

class NiOBBNode
{
public:
    NiOBBNode();
    virtual ~NiOBBNode()
    {
        if (unk88)
        {
            delete unk88;
            delete unk90;
        }
    }

    char unk08[0x80];
    NiOBBNodeChild* unk88;
    NiOBBNodeChild* unk90;
    char unk98[0x8];
};
static_assert(sizeof(NiOBBNode) == 0xA0, "NiOBBNode size from the deleting destructor");
