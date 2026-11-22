// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: body written from the pinned image listing; names and declarations from community headers
// 0x1ef710 TESRaceForm::TESRaceForm
// Adapted bodies: none
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
#include "TESRaceForm.h"

TESRaceForm::TESRaceForm()
{
    race = nullptr;
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
