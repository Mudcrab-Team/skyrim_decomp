// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1dee90 TESAIForm::Function1dee90
// 0x1dee20 TESAIForm::Function1dee20
// Adapted bodies: none
#include "TESAIForm.h"
#include <cstring>

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

void TESAIForm::CopyComponent(BaseFormComponent* a_rhs)
{
    TESAIForm* rhs = dynamic_cast<TESAIForm*>(a_rhs);
    if (!rhs) {
        return;
    }
    memcpy_s(&aiData, sizeof(aiData), &rhs->aiData, sizeof(aiData));
    aiPackages.CopyPackages(rhs->aiPackages);
}

// Not compared: defined so the unit emits the class vftable and, beside it, the deleting destructor
// compared at 0x1df010.
TESAIForm::TESAIForm()
{
}

TESAIForm::~TESAIForm()
{
    aiPackages.Clear();
}

std::uint16_t TESAIForm::Function1dee20(std::uint32_t a_index) const
{
    return aiData.aggroRadius[a_index];
}

void TESAIForm::Function1dee90()
{
    aiPackages.Function4a2670();
}
