// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// 0x1c8500 BGSStoryManagerBranchNode::QChildCount
// 0x1c7cd0 BGSStoryManagerBranchNode::GetChild
// 0x5358d0 BGSStoryManagerBranchNode::InitItemImpl
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
