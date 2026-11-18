// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x1db110 BGSPerkRankArray::ClearDataComponent
#include "BGSPerkRankArray.h"

void BGSPerkRankArray::InitializeDataComponent()
{
}

void BGSPerkRankArray::ClearDataComponent()
{
    FreePerks(false);
}
