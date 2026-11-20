// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x31d7b0 BGSImpactData::InitializeData
#include "BGSImpactData.h"

void BGSImpactData::InitializeData()
{
    data.soundLevel = 1;
    data.flags = 0;
    data.resultOverride = 0;
    data.unk16 = 0;
    data.effectDuration = 0.25f;
    data.orient = 2;
    data.angleThreshold = 15.0f;
    data.placementRadius = 16.0f;
    decalTextureSet = nullptr;
    decalTextureSet2 = nullptr;
    sound1 = nullptr;
    sound2 = nullptr;
    hazard = nullptr;
}
