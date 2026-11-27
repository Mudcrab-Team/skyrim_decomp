// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3279b0 BGSMusicType::DoUpdate
// Adapted bodies: BGSMusicType::DoUpdate, from the anonymous permitted sibling game code, rewritten
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicType.cpp:15
#include "BGSMusicType_3279b0.h"

// Keeps the type's status in step with its current track, then lets the track update.
void BGSMusicType::DoUpdate()
{
    if (!tracks.size()) {
        typeStatus = kFinished;
        return;
    }
    if (static_cast<std::uint32_t>(typeStatus) - kFinishing > 1 && tracks[currentTrackIndex]->GetMusicStatus() == kFinished) {
        if (!flags.any(kPlaysOnce)) {
            typeStatus = kInactive;
        } else {
            flags.set(kRemovalQueued);
            typeStatus = kFinished;
        }
    } else if (typeStatus == kFinishing) {
        typeStatus = tracks[currentTrackIndex]->GetMusicStatus();
    }
    tracks[currentTrackIndex]->DoUpdate();
}
