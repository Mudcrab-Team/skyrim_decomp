// 0x535ce0 BGSStoryManagerEventNode::InitItemImpl
// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: project-authored reconstruction restored from an archived draft.
// BGSStoryManagerEventNode::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
#include "BGSStoryManagerEventNode_535ce0.h"

void BGSStoryManagerEventNode::InitItemImpl()
{
    if (TestBit(formFlags, 3)) {
        return;
    }
    BGSStoryManagerBranchNode::InitItemImpl();
    const std::uint32_t formID = *reinterpret_cast<const std::uint32_t*>(reinterpret_cast<const std::uint8_t*>(this) + 0x60);
    const std::int32_t index = BGSStoryEventManager::GetSingleton()->FindStoryEventIndex(formID);
    if (index != -1) {
        event = BGSStoryEventManager::GetSingleton()->GetStoryEventAt(index);
        RegisterStoryEventNode(g_storyEventNodeRegistry, event, this);
    } else {
        event = nullptr;
    }
    SetFormFlag(true);
}
