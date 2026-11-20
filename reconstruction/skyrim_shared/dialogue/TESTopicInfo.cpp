// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x3f3150 TESTopicInfo::LoadGame
// 0x3f3180 TESTopicInfo::Revert
#include "TESTopicInfo.h"

void TESTopicInfo::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    if (static_cast<std::int32_t>(a_buf->changeFlags) < 0) {
        saidOnce = true;
    }
}

void TESTopicInfo::Revert(BGSLoadFormBuffer* a_buf)
{
    TESForm::Revert(a_buf);
    if (static_cast<std::int32_t>(a_buf->oldChangeFlags) < 0) {
        saidOnce = false;
    }
}
