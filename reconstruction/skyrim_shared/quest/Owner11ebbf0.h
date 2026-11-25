// Code origin: original declarations with the labelled community layouts and member names. Stamped as a twin of matched 0x535900 (skyrim_shared/quest/BGSStoryManagerBranchNode): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ::QChildCount, ::GetChild, ::InitItemImpl, ::children: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::InitItemImpl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerTreeForm, ::QChildCount, ::GetChild, ::AcceptVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerTreeForm: EXE_RTTI; class name and base from the image RTTI
// BGSStoryManagerTreeVisitor, BGSStoryManagerTreeVisitor::VisitControl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the type is needed for the slot signature
// BGSStoryManagerTreeForm::AcceptVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; slot 3E, only the slot matters here
// BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the listing, NG wraps it in an allocator
// Owner11ebbf0: GUESS(low) STANDIN
// BGSStoryManagerNodeBase: GUESS(low) STANDIN
#pragma once
#include "BGSStoryManagerBranchNode.h"

class Owner11ebbf0 : public BGSStoryManagerNodeBase {
public:
    void                     InitItemImpl() override;                   // 13
    std::uint32_t            QChildCount() const override;              // 3B
    BGSStoryManagerTreeForm* GetChild(std::uint32_t a_idx) const override;  // 3C

    BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;
    void SetFormFlag(bool a_set);

    // members
    BSTArray<BGSStoryManagerNodeBase*> children;  // 48
};
static_assert(sizeof(Owner11ebbf0) == 0x60, "layout");
