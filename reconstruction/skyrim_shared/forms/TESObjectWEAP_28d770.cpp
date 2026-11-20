// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x28d770 TESObjectWEAP::SaveGame
// 0x28d7b0 TESObjectWEAP::LoadGame
// Adapted bodies: none
#include "TESObjectWEAP_28d770.h"

// LoadValueState: GUESS(low)
void LoadValueState(void* value, BGSLoadFormBuffer* buffer);
// SaveValueState: GUESS(low)
void SaveValueState(void* value, BGSSaveFormBuffer* buffer);

void TESObjectWEAP::SaveGame(BGSSaveFormBuffer* buffer)
{
    TESForm::SaveGame(buffer);
    return SaveValueState(valueForm, buffer);
}

void TESObjectWEAP::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    return LoadValueState(valueForm, buffer);
}
