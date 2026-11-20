// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x387ea0 TESShout::GetKnown
#include "TESShout.h"

bool TESShout::GetKnown() const
{
    for (std::uint32_t i = 0; i < 3; ++i) {
        if (variations[i].word) {
            return (variations[i].word->formFlags >> 16) & 1;
        }
    }
    return false;
}
