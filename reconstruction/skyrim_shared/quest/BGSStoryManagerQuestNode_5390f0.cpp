// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x5390f0 BGSStoryManagerQuestNode::ReadFromSaveGame_1404D6340
// Adapted bodies: none
#include "BGSStoryManagerQuestNode_5390f0.h"

// Reads per-quest last-run timestamps from a save buffer into childrenLastRun.
void BGSStoryManagerQuestNode::ReadFromSaveGame_1404D6340(BGSLoadFormBuffer* a_buf)
{
    BGSStoryManagerNodeBase::ReadFromSaveGame(a_buf);

    std::uint32_t count = 0;
    float value = 0.0f;
    a_buf->Read(&count, 4, 4);

    for (std::uint32_t i = 0; i < count; ++i) {
        a_buf->Read(&value, 4, 4);
        if (i < quests.size) {
            childrenLastRun.data[i] = value;
        }
    }
}
