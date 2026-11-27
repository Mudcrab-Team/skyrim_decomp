// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3286a0 BGSMusicType::dtor
// CI hash: 0x3286a0 ??_GBGSMusicType@@UEAAPEAXI@Z
// Adapted bodies: none
#include "BGSMusicType_3286a0.h"

// the full deleting destructor: both arrays are released, then the plain members are reset
BGSMusicType::~BGSMusicType()
{
    tracks.Clear();
    trackHistory.Clear();
    fadeTime = 0.0f;
    currentTrackIndex = 0;
    flags = 0;
    priority = 50;
    ducksOtherMusicBy = 0;
}
