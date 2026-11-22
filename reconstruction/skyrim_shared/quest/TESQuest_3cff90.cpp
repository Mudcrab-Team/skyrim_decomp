// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// 0x3cff90 TESQuest::GetObjective
#include "TESQuest_3cff90.h"

BGSQuestObjective* TESQuest::GetObjective(std::uint32_t a_id)
{
    for (auto* node = &objectives; node; node = node->next) {
        // BSSimpleList stores its first element inline: a node with no item and no next is the empty list.
        if (!node->next && !node->item) {
            break;
        }
        auto* item = node->item;
        if (item && item->index == a_id) {
            return item;
        }
    }
    return nullptr;
}
