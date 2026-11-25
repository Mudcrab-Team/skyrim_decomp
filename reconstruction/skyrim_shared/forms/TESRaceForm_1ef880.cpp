// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESRaceForm.cpp:74
// 0x1ef880 TESRaceForm::GetFormRace
// CI hash: 0x1ef880 ?GetFormRace@TESRaceForm@@SAPEAVTESRace@@PEAVTESForm@@@Z
#include "TESRaceForm_1ef880.h"

TESRace* TESRaceForm::GetFormRace(TESForm* a_form)
{
    TESRaceForm* raceForm = dynamic_cast<TESRaceForm*>(a_form);
    if (raceForm)
        return raceForm->race;
    return nullptr;
}
