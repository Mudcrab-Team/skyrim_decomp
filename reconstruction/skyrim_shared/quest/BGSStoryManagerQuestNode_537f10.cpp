// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x537f10 BGSStoryManagerQuestNode::QChildCount
// 0x538390 BGSStoryManagerQuestNode::GetChild
// Adapted bodies: none
#include "BGSStoryManagerQuestNode_537f10.h"

std::uint32_t BGSStoryManagerQuestNode::QChildCount() const
{
    return childCount;
}

BGSStoryManagerTreeForm* BGSStoryManagerQuestNode::GetChild(std::uint32_t index) const
{
    return children[index];
}
