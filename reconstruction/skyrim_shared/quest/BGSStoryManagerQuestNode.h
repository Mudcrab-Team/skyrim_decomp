// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStoryManagerQuestNode, ::Revert, ::quests, ::numQuestsToStart, ::padC4, ::childrenLastRun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerQuestNode::unk60: GUESS(low); stands for perQuestFlags and perQuestHoursUntilReset (two BSTHashMap at 60 and 90 in NG), not modelled
// BGSStoryManagerNodeBase, ::Flags, ::parent, ::previousSibling, ::maxQuests, ::flags, ::conditions, ::QConditions, ::InitializeData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerNodeBase::Flags::nodeFlags, ::questFags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain 16-bit integers here
// BGSStoryManagerTreeForm, ::QChildCount, ::GetChild, ::QConditions, ::AcceptVisitor, ::lastVisitorID, ::pad24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerTreeForm: EXE_RTTI; class name and base from the image RTTI
// BGSStoryManagerTreeVisitor, BGSStoryManagerTreeVisitor::VisitControl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the type is needed for the slot signature
// BGSStoryManagerTreeForm::AcceptVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; slot 3E, only the slot matters here
// TESCondition, TESCondition::head: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pointer, sized from the 0x48 class size
// BSTArray, BSTArray::data, ::capacity, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the listing, NG wraps it in an allocator
#pragma once

#include <cstdint>

#include "BGSStoryManagerBranchNode.h"

class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase {
public:
    void Revert(BGSLoadFormBuffer* a_buf) override;  // 12
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E

    BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;

    // members
    BSTArray<TESQuest*> quests;           // 48
    std::uint8_t        unk60[0x60];      // 60
    std::uint32_t       numQuestsToStart; // C0
    std::uint32_t       padC4;            // C4
    BSTArray<float>     childrenLastRun;  // C8
};
static_assert(sizeof(BGSStoryManagerQuestNode) == 0xE0, "layout");

// BGSStoryManagerNodeBaseSaveGame: GUESS(low); the non-virtual base save that SaveGame calls first
// (RVA 0x1e5700), declared without a body.
void BGSStoryManagerNodeBaseSaveGame(BGSStoryManagerQuestNode* a_node, BGSSaveFormBuffer* a_buf);
