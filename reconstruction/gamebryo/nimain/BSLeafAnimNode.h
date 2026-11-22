// Source exposure: mixed
// Origin: original reconstruction from the pinned image and an anonymous sibling; nothing else includes this header.
// Code origin: original; the pinned listing and community declarations only
// NiNode::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFadeNode as BSLeafAnimNode's base: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, BSFadeNode, NiNode::~NiNode, BSFadeNode::~BSFadeNode, BSLeafAnimNode::~BSLeafAnimNode: STANDIN GUESS(low); the chain is the image's own tail jumps (0x14e89b0 -> 0x14e5e90 -> 0xee19d0), and the stand-ins are local because this header is included by this unit alone
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class NiStream;
class NiNode
{
public:
    virtual ~NiNode();
    bool RegisterStreamables(NiStream&);
};
class BSFadeNode : public NiNode
{
public:
    virtual ~BSFadeNode();
};
class BSLeafAnimNode : public BSFadeNode
{
public:
    virtual ~BSLeafAnimNode();
    bool RegisterStreamables(NiStream&);
};
