// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1ee470 TESProduceForm::InitializeDataComponent
// 0x1eee40 TESProduceForm::~TESProduceForm
#include "TESProduceForm.h"

TESProduceForm::TESProduceForm()
{
}

TESProduceForm::~TESProduceForm()
{
}

void TESProduceForm::InitializeDataComponent()
{
    produceItem = nullptr;
    harvestSound = nullptr;
    for (int i = 0; i < 4; ++i) {
        produceChance[i] = 0;
    }
}

void TESProduceForm::ClearDataComponent()
{
}
