// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x2a8170 TESImageSpaceModifier::ClearData
#include "TESImageSpaceModifier_2a8170.h"

void TESImageSpaceModifier::ClearData()
{
    for (std::size_t i = 0; i < 21; ++i) {
        for (std::size_t j = 0; j < 2; ++j) {
            pairs[i][j] = nullptr;
        }
    }
    ptr278 = nullptr;
    ptr280 = nullptr;
    ptr268 = nullptr;
    ptr270 = nullptr;
    ptr288 = nullptr;
    ptr290 = nullptr;
    ptr298 = nullptr;
    ptr2A0 = nullptr;
    ptr2A8 = nullptr;
    ptr2B0 = nullptr;
    ptr2B8 = nullptr;
    ptr2C0 = nullptr;
    ptr2C8 = nullptr;
    TESForm::ClearData();
}
