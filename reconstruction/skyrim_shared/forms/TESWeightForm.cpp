// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x1f3760 TESWeightForm::CopyComponent
#include "TESWeightForm.h"

void TESWeightForm::CopyComponent(BaseFormComponent* a_rhs)
{
    TESWeightForm* rhs = dynamic_cast<TESWeightForm*>(a_rhs);
    if (rhs) {
        weight = rhs->weight;
    }
}
