// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1c8520 (skyrim_shared/quest/BGSStoryManagerNodeBase): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ::Flags, ::parent, ::previousSibling, ::maxQuests, ::flags, ::conditions, ::QConditions, ::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::questFags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain 16-bit integers here, NG wraps them in stl::enumeration
// ::QConditions: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCondition: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pointer, sized from the 0x48 class size
// Ownerb86b90: GUESS(low) STANDIN
// BGSStoryManagerTreeForm: GUESS(low) STANDIN
#pragma once
#include "BGSStoryManagerNodeBase.h"

class Ownerb86b90 : public BGSStoryManagerTreeForm {
public:
    struct Flags {
        std::uint16_t nodeFlags;  // 0
        std::uint16_t questFags;  // 2
    };
    static_assert(sizeof(Flags) == 0x4, "layout");

    Ownerb86b90();
    ~Ownerb86b90() override;

    void          InitializeData() override;  // 04
    void          ClearData() override;
    TESCondition* QConditions() override;     // 3D

    // members
    BGSStoryManagerBranchNode* parent;           // 28
    Ownerb86b90*   previousSibling;  // 30
    std::uint32_t              maxQuests;        // 38
    Flags                      flags;            // 3C
    TESCondition               conditions;       // 40
};
static_assert(sizeof(Ownerb86b90) == 0x48, "layout");
