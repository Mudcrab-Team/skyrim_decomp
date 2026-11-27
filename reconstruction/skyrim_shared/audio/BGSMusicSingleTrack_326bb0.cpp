// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x326bb0 BGSMusicSingleTrack::~BGSMusicSingleTrack
// CI hash: 0x326bb0 ??_GBGSMusicSingleTrack@@UEAAPEAXI@Z
// Adapted bodies: none
#include "BGSMusicSingleTrack_326bb0.h"

// Emits the vftable so the compiler generates the scalar deleting destructor.
BGSMusicSingleTrack::BGSMusicSingleTrack() = default;

// Deletes the loop info object, destroys the cue points array, and invokes the base destructor.
BGSMusicSingleTrack::~BGSMusicSingleTrack()
{
    delete loopInfo;
}
