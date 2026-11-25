// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original declarations incorporating the labelled community types and observed list layout. Stamped as a twin of matched 0x3dfeb0 (skyrim_shared/quest/TESQuest): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ::QConditions, ::GetFormEditorID, ::FinishLoadGame, ::InitializeData, ::instanceData, ::currentInstanceID, ::aliases, ::data, ::eventID, ::objConditions, ::currentStage, ::alreadyRun, ::formEditorID, ::startEventData, ::promoteTask, ::promotedRefs, ::pad054, ::pad0E4, ::pad22B, ::pad22C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::unk70, ::unkF8, ::unk110, ::unk220: GUESS(low); regions outside the compared access paths.
// QUEST_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain integers for the stl::enumeration members
// BGSBaseAlias: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArray, BSTArray::data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the listings, NG wraps it in an allocator
// BSString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); data pointer first, the length fields are placeholders
// QueuedPromoteQuestTask: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::QConditions: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCondition: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pointer
// TESQuestStage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner11dee90: GUESS(low) STANDIN
// BGSStoryManagerTreeForm: GUESS(low) STANDIN
#pragma once
#include "TESQuest.h"

class Owner11dee90 : public BGSStoryManagerTreeForm {
public:
    struct StageEntry {
        TESQuestStage* stage;
        StageEntry* next;
    };

    Owner11dee90();
    ~Owner11dee90() override;  // 00

    void          InitializeData() override;                       // 04
    void          FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
    const char*   GetFormEditorID() const override;                // 32
    TESCondition* QConditions() override;                          // 3D
    TESQuestStage* FindStage(std::uint16_t a_index) const;

    // members
    std::uint8_t            unk28[0x10];      // 28
    BSTArray<void*>         instanceData;     // 38
    std::uint32_t           currentInstanceID;  // 50
    std::uint32_t           pad054;           // 54
    BSTArray<BGSBaseAlias*> aliases;          // 58
    std::uint8_t            unk70[0x68];      // 70
    QUEST_DATA              data;             // D8
    std::uint32_t           eventID;          // E0
    std::uint32_t           pad0E4;           // E4
    StageEntry              executedStages;   // E8
    std::uint8_t            unkF8[0x10];       // F8
    TESCondition            objConditions;    // 108
    std::uint8_t            unk110[0x110];    // 110
    void*                   unk220;           // 220
    std::uint16_t           currentStage;     // 228
    bool                    alreadyRun;       // 22A
    std::uint8_t            pad22B;           // 22B
    std::uint32_t           pad22C;           // 22C
    BSString                formEditorID;     // 230
    const void*             startEventData;   // 240
    QueuedPromoteQuestTask* promoteTask;      // 248
    BSTArray<std::uint32_t> promotedRefs;     // 250
};
static_assert(sizeof(Owner11dee90) == 0x268, "layout");
