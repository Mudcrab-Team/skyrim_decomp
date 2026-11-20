// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// 0x306f80 TESWaterForm::GetDangerous
// 0x3078e0 TESWaterForm::~TESWaterForm
#include "TESWaterForm.h"

// Not compared: defined so that this unit emits the vftable and with it the deleting destructor.
TESWaterForm::TESWaterForm()
{
}

bool TESWaterForm::GetDangerous() const
{
    return flags & 1;
}
