// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiNode, AsBSFadeNode: CRASHLOGGER_PDB(59818@2026.10.24); the PDB name carries an address suffix, dropped here
// AsFadeNode, parent, BSFadeNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots and members used here
// unk00, unk08, unk10, unk18, unk20, unk08Data, ParentNode: GUESS(low); vtable slots and padding in front of the used ones
#pragma once

#include <cstdint>
#include <cstddef>

class BSFadeNode;

class NiNode
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual void unk18();
    virtual void unk20();
    virtual BSFadeNode* AsFadeNode();

    static BSFadeNode* AsBSFadeNode(NiNode* start);

    unsigned char unk08Data[0x28];
    NiNode* parent;
    NiNode* ParentNode() const { return parent; }
};
static_assert(offsetof(NiNode, parent) == 0x30, "parent offset");

