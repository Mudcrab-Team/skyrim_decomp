// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the listings using the cited list declarations.
// Adapted bodies: none
// 0x1de8d0 TESAIForm::ClearPackageList
// 0x1de940 TESAIForm::CopyPackageList
#include "TESAIForm_1de940.h"

// skipPackageClear: STANDIN GUESS(low)
extern const bool skipPackageClear;

void TESAIForm::ClearPackageList()
{
    if (!skipPackageClear) {
        aiPackages.Function4a2ce0();
    }
}

void TESAIForm::CopyPackageList(const TESAIForm& source)
{
    aiPackages.CopyFrom(source.aiPackages);
}
