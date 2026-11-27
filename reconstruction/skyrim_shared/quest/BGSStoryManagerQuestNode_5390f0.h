// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSStoryManagerQuestNode, BGSStoryManagerQuestNode::ReadFromSaveGame_1404D6340, BGSStoryManagerNodeBase, BGSStoryManagerQuestNode::quests, BGSStoryManagerQuestNode::childrenLastRun: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSLoadFormBuffer, FloatArray, QuestArray, ReadFromSaveGame, Read, unk00, unk60: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BGSLoadFormBuffer
{
public:
    void Read(void* a_dest, std::uint32_t a_size, std::uint32_t a_count);
};

class BGSStoryManagerNodeBase
{
public:
    void ReadFromSaveGame(BGSLoadFormBuffer* a_buf);

    std::uint8_t unk00[0x48];
};
static_assert(sizeof(BGSStoryManagerNodeBase) == 0x48, "BGSStoryManagerNodeBase size");

struct QuestArray
{
    void** data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};

struct FloatArray
{
    float* data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};

class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase
{
public:
    void ReadFromSaveGame_1404D6340(BGSLoadFormBuffer* a_buf);

    QuestArray quests;
    std::uint8_t unk60[0xC8 - 0x60];
    FloatArray childrenLastRun;
};
static_assert(offsetof(BGSStoryManagerQuestNode, quests) == 0x48, "BGSStoryManagerQuestNode::quests offset");
static_assert(offsetof(BGSStoryManagerQuestNode, childrenLastRun) == 0xC8, "BGSStoryManagerQuestNode::childrenLastRun offset");
