// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1db110 BGSPerkRankArray::ClearDataComponent
#include "BGSPerkRankArray.h"

void BGSPerkRankArray::InitializeDataComponent()
{
}

void BGSPerkRankArray::ClearDataComponent()
{
    FreePerks(false);
}
