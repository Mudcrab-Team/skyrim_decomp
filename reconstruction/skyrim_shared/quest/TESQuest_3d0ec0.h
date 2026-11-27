// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESQuest: EXE_RTTI
// TESQuest::IsStageDone: CRASHLOGGER_PDB(59818@2026.10.24)
// TESQuest::unk000, TESQuest::executedStages, QuestStageData, QuestStageData::index, QuestStageData::flags, SimpleListNode, SimpleListNode::item, SimpleListNode::next, SimpleListNode::IsEmpty: GUESS(low); offsets observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

struct QuestStageData
{
    std::uint16_t index;  // 00
    std::uint8_t  flags;  // 02
};

template <class T>
struct SimpleListNode
{
    bool IsEmpty() const { return !next && !item; }

    T               item;  // 00
    SimpleListNode* next;  // 08
};

class TESQuest
{
public:
    bool IsStageDone(std::uint16_t a_stage) const;

    std::uint8_t                    unk000[0xE8];    // 000
    SimpleListNode<QuestStageData*> executedStages;  // 0E8
};
static_assert(offsetof(TESQuest, executedStages) == 0xE8, "TESQuest::executedStages offset");
