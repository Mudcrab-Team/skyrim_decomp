// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x1de820 TESAIForm::ClearDataComponent
// 0x1de800 TESAIForm::InitializeDataComponent
#include "TESAIForm.h"

void TESAIForm::ClearDataComponent()
{
    aiPackages.Clear();
}

void TESAIForm::InitializeDataComponent()
{
    aiData.aggression1 = 0;
    aiData.aggression2 = 0;
    aiData.confidence1 = 0;
    aiData.confidence2 = 0;
    aiData.confidence3 = 1;
    aiData.energyLevel1 = 0;
    aiData.energyLevel2 = 0;
    aiData.energyLevel3 = 0;
    aiData.energyLevel4 = 0;
    aiData.energyLevel5 = 0;
    aiData.energyLevel6 = 0;
    aiData.energyLevel7 = 0;
    aiData.energyLevel8 = 0;
    aiData.morality1 = 1;
    aiData.morality2 = 1;
    aiData.mood1 = 0;
    aiData.mood2 = 0;
    aiData.mood3 = 0;
    aiData.assistance1 = 0;
    aiData.assistance2 = 0;
    aiData.aggroRadiusBehaviour = 0;
    aiData.aggroRadius[0] = 0;
    aiData.aggroRadius[1] = 0;
    aiData.aggroRadius[2] = 0;
}
