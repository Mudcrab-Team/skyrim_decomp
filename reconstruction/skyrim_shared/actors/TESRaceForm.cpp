// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x1ef750 TESRaceForm::CopyComponent
#include "TESRaceForm.h"

TESRaceForm::TESRaceForm()
{
}

void TESRaceForm::ClearDataComponent()
{
}

void TESRaceForm::InitializeDataComponent()
{
    race = nullptr;
}

void TESRaceForm::CopyComponent(BaseFormComponent* a_rhs)
{
    TESRaceForm* rhs = dynamic_cast<TESRaceForm*>(a_rhs);
    if (rhs) {
        race = rhs->race;
    }
}
