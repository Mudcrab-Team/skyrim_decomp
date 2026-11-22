// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStoryManagerBranchNode, ::QChildCount, ::GetChild, ::InitItemImpl, ::children: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerBranchNode::SetFormFlag: GUESS(low); a non-virtual TESForm helper at 0x1e60b0 taking this and a bool, called at the end of InitItemImpl; declared here because TESForm.h has no such member (header-gap TESForm)
// BGSStoryManagerNodeBase, ::Flags, ::parent, ::previousSibling, ::maxQuests, ::flags, ::conditions, ::QConditions, ::InitializeData, ::InitItemImpl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerNodeBase::Flags::nodeFlags, ::questFags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain 16-bit integers here
// BGSStoryManagerTreeForm, ::QChildCount, ::GetChild, ::QConditions, ::AcceptVisitor, ::lastVisitorID, ::pad24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerTreeForm: EXE_RTTI; class name and base from the image RTTI
// BGSStoryManagerTreeVisitor, BGSStoryManagerTreeVisitor::VisitControl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the type is needed for the slot signature
// BGSStoryManagerTreeForm::AcceptVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; slot 3E, only the slot matters here
// TESCondition, TESCondition::head: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pointer, sized from the 0x48 class size
// BSTArray, BSTArray::data, ::capacity, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the listing, NG wraps it in an allocator
#pragma once

#include <cstdint>

#include "skyrim_shared/forms/TESForm.h"

template <class T>
class BSTArray {
public:
    T*            data;      // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;     // 0C
    std::uint32_t size;      // 10
    std::uint32_t pad14;     // 14
};
static_assert(sizeof(BSTArray<void*>) == 0x18, "layout");

class BGSStoryManagerBranchNode;
class BGSStoryManagerQuestNode;
class BGSStoryManagerTreeForm;
class PeriodicUpdateTimer;
class TESQuest;

// Visitor dispatch and fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSStoryManagerTreeVisitor {
public:
    enum class VisitControl : std::int32_t {
    };

    virtual ~BGSStoryManagerTreeVisitor();
    virtual VisitControl VisitBranchNode(BGSStoryManagerBranchNode& a_node);
    virtual VisitControl VisitQuestNode(BGSStoryManagerQuestNode& a_node, bool a_entering);
    virtual VisitControl VisitQuest(TESQuest& a_quest);
    virtual void Revert();

    PeriodicUpdateTimer* timer;
    std::int32_t currentCursorDepth;
    BGSStoryManagerQuestNode* lastQuestParent;
    BSTArray<BGSStoryManagerTreeForm*> cursorAncestry;
    std::uint32_t queryID;
};
static_assert(sizeof(BGSStoryManagerTreeVisitor) == 0x40, "story visitor size");

class TESCondition {
public:
    void* head;  // 00
};

class BGSStoryManagerTreeForm : public TESForm {
public:
    ~BGSStoryManagerTreeForm() override;  // 00

    virtual std::uint32_t                            QChildCount() const;                                       // 3B
    virtual BGSStoryManagerTreeForm*                 GetChild(std::uint32_t a_idx) const;                       // 3C
    virtual TESCondition*                            QConditions() = 0;                                         // 3D
    virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) = 0;  // 3E

    // members
    std::uint32_t lastVisitorID;  // 20
    std::uint32_t pad24;          // 24
};
static_assert(sizeof(BGSStoryManagerTreeForm) == 0x28, "layout");

class BGSStoryManagerBranchNode;

class BGSStoryManagerNodeBase : public BGSStoryManagerTreeForm {
public:
    struct Flags {
        std::uint16_t nodeFlags;  // 0
        std::uint16_t questFags;  // 2
    };
    static_assert(sizeof(Flags) == 0x4, "layout");

    void          InitializeData() override;  // 04
    void          InitItemImpl() override;    // 13
    TESCondition* QConditions() override;     // 3D

    // members
    BGSStoryManagerBranchNode* parent;           // 28
    BGSStoryManagerNodeBase*   previousSibling;  // 30
    std::uint32_t              maxQuests;        // 38
    Flags                      flags;            // 3C
    TESCondition               conditions;       // 40
};
static_assert(sizeof(BGSStoryManagerNodeBase) == 0x48, "layout");

class BGSStoryManagerBranchNode : public BGSStoryManagerNodeBase {
public:
    void                     InitItemImpl() override;                   // 13
    std::uint32_t            QChildCount() const override;              // 3B
    BGSStoryManagerTreeForm* GetChild(std::uint32_t a_idx) const override;  // 3C

    BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;
    void SetFormFlag(bool a_set);

    // members
    BSTArray<BGSStoryManagerNodeBase*> children;  // 48
};
static_assert(sizeof(BGSStoryManagerBranchNode) == 0x60, "layout");
