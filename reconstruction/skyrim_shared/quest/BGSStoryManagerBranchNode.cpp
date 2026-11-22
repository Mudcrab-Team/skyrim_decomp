// Source exposure: mixed (community declarations and the pinned image listing).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction with the labelled visitor interface.
// Adapted bodies: none.
// BGSStoryManagerBranchNode::AcceptVisitor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x1c8500 BGSStoryManagerBranchNode::QChildCount
// 0x1c7cd0 BGSStoryManagerBranchNode::GetChild
// 0x5358d0 BGSStoryManagerBranchNode::InitItemImpl
// 0x535900 BGSStoryManagerBranchNode::AcceptVisitor
#include "BGSStoryManagerBranchNode.h"

std::uint32_t BGSStoryManagerBranchNode::QChildCount() const
{
    return children.size;
}

BGSStoryManagerTreeForm* BGSStoryManagerBranchNode::GetChild(std::uint32_t a_idx) const
{
    return children.data[a_idx];
}

void BGSStoryManagerBranchNode::InitItemImpl()
{
    BGSStoryManagerNodeBase::InitItemImpl();
    SetFormFlag(true);
}

// Dispatch the visitor to this story branch.
BGSStoryManagerTreeVisitor::VisitControl BGSStoryManagerBranchNode::AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor)
{
    return a_visitor.VisitBranchNode(*this);
}
