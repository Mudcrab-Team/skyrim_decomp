// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x275250 TESObjectLIGH::LoadGame
// Adapted bodies: none
#include "TESObjectLIGH_275250.h"

// LoadValueState: GUESS(low)
void LoadValueState(void* value, BGSLoadFormBuffer* buffer);

void TESObjectLIGH::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    return LoadValueState(valueForm, buffer);
}
