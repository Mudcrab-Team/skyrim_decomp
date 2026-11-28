// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x3df960 QueuedPromoteQuestTask::sub_140380420
#include "QueuedPromoteQuestTask_3df960.h"

// Format a task description using the quest name and form ID.
bool QueuedPromoteQuestTask::sub_140380420(char* a_buf, std::uint32_t a_size)
{
    TESQuest3df960* q = quest;
    std::uint32_t id = q->formID;
    const char* name = q->GetName();
    FormatTaskDesc(a_buf, a_size, gPromoteQuestFormat, name, id);
    return true;
}
