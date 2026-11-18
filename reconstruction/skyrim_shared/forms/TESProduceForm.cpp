// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
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
