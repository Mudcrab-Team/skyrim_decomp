// Source exposure: mixed (community declarations and the pinned image listing).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction with the labelled visitor interface.
// Adapted bodies: none.
// BGSStoryManagerQuestNode::AcceptVisitor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x539020 BGSStoryManagerQuestNode::Revert
// 0x539050 BGSStoryManagerQuestNode::SaveGame
// 0x538c20 BGSStoryManagerQuestNode::AcceptVisitor
#include "BGSStoryManagerQuestNode.h"

void BGSStoryManagerQuestNode::Revert(BGSLoadFormBuffer*)
{
    for (std::uint32_t i = 0; i < quests.size; ++i) {
        childrenLastRun.data[i] = 0.0f;
    }
}

// BGSStoryManagerQuestNode::SaveGame, RVA 0x539050, 143 bytes. Saves the base record, then the quest count
// and each child's saved value.
void BGSStoryManagerQuestNode::SaveGame(BGSSaveFormBuffer* a_buf)
{
    BGSStoryManagerNodeBaseSaveGame(this, a_buf);

    std::uint32_t count = quests.size;
    a_buf->SaveDataEndian(&count, 4, 4, 0);
    std::uint32_t i = 0;
    if (count > i) {
        do {
            a_buf->SaveDataEndian(&childrenLastRun.data[i], 4, 4, 0);
            i = i + 1;
        } while (i < count);
    }
}

// Dispatch the visitor to this quest node on entry.
BGSStoryManagerTreeVisitor::VisitControl BGSStoryManagerQuestNode::AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor)
{
    return a_visitor.VisitQuestNode(*this, true);
}
