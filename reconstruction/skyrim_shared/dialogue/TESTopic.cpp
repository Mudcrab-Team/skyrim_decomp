// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x3eee90 TESTopic::IsFormTypeChild
#include "TESTopic.h"

bool TESTopic::IsFormTypeChild(FormType a_type)
{
    // kInfoFormType: GUESS(low); 0x4c
    return a_type == static_cast<FormType>(0x4c);
}
