// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x3d0ec0 TESQuest::IsStageDone
// Adapted bodies: none
#include "TESQuest_3d0ec0.h"

// Returns true if the given quest stage is present in the executed stage list with bit 0 set.
bool TESQuest::IsStageDone(std::uint16_t a_stage) const
{
    for (const SimpleListNode<QuestStageData*>* node = &executedStages; node && !node->IsEmpty(); node = node->next) {
        QuestStageData* stage = node->item;
        if (stage->index == a_stage) {
            return (stage->flags & 1) != 0;
        }
    }
    return false;
}
