// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x326d50 BGSMusicTrack::~BGSMusicTrack
// Adapted bodies: BGSMusicTrack::~BGSMusicTrack follows fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrack.cpp:11
#include "BGSMusicTrack_326d50.h"

BGSMusicTrack::~BGSMusicTrack()
{
    if (pConditions)
    {
        delete pConditions;
    }
}
