// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x539020 BGSStoryManagerQuestNode::Revert
// 0x539050 BGSStoryManagerQuestNode::SaveGame
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
