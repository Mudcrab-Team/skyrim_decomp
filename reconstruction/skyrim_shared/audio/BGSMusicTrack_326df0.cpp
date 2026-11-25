// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x326df0 BGSMusicTrack::LoadConditions
// Adapted bodies: BGSMusicTrack::LoadConditions follows fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:45
#include "BGSMusicTrack_326df0.h"

void BGSMusicTrack::LoadConditions(TESFile* apFile)
{
    delete pConditions;
    pConditions = new TESCondition;
    pConditions->LoadCompact(apFile);
}
