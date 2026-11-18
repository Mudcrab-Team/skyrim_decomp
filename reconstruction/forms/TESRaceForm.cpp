// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
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
