// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x25bac0 BGSAddonNode::InitItemImpl
// 0x25c0e0 BGSAddonNode::~BGSAddonNode
#include "BGSAddonNode.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
BGSAddonNode::BGSAddonNode() {}
BGSAddonNode::~BGSAddonNode() { if(AddonDataHandler) RemoveAddonNode(AddonDataHandler,this); }
void BGSAddonNode::InitItemImpl() { if(!TestBit(formFlags,3)) { ResolveAddonModels(this,this); std::uint32_t id=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(sound)); if(id) { ResolveAddonID(&id,AddonSourceFile(this,-1)); sound=LookupAddonSound(id); } MarkAddonNode(this,true); } }

