// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: adapted permitted sibling body with target-observed layout
// SPDX-License-Identifier: CC0-1.0
// 0x1de8f0 TESAIForm::Function1de8f0
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESAIForm.cpp:71
// Adapted bodies: TESAIForm::Function1de8f0 from TESAIForm::CopyAIData, fo4-private@1b765c70 src/Shared/FormComponents/TESAIForm.cpp:71, author-permission.
#include "TESAIForm_1de8f0.h"
#include <cstring>

void TESAIForm::Function1de8f0(TESAIForm* source)
{
    memcpy_s(AIData, sizeof(AIData), source->AIData, sizeof(source->AIData));
}
