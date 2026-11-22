// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// TESLoadScreen::CanDisplay, TESCondition::IsTrue: CRASHLOGGER_PDB(59818@2026.10.24)
// g_loadScreenConditionSubject: GUESS(low)
// 0x340ec0 TESLoadScreen::ClearData
// 0x341670 TESLoadScreen::Function341670
// 0x341650 TESLoadScreen::CanDisplay
#include "TESLoadScreen.h"

void TESLoadScreen::InitializeData()
{
}

void TESLoadScreen::ClearData()
{
    conditions.Clear();
    if (loadNIFData) {
        loadNIFData->cameraPath.ClearDataComponent();
    }
    TESForm::ClearData();
}
// Test whether the load screen's conditions allow it to be displayed.
bool TESLoadScreen::CanDisplay() const
{
    return conditions.IsTrue(g_loadScreenConditionSubject, g_loadScreenConditionSubject);
}

// Report whether the load screen has any conditions.
bool TESLoadScreen::Function341670() const
{
    return conditions.head == nullptr;
}
