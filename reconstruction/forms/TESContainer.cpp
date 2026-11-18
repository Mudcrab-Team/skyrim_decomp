// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1e0b10 TESContainer::GetItemCount
#include "TESContainer.h"

std::int32_t TESContainer::GetItemCount(TESBoundObject* a_object) const
{
    std::int32_t total = 0;
    for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
        if (containerObjects[i] && containerObjects[i]->obj == a_object) {
            total += containerObjects[i]->count;
        }
    }
    return total;
}

// TESContainer::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESContainer::InitializeDataComponent()
{
}
