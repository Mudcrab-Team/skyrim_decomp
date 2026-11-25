// Source exposure: mixed
// Code origin: adapted timing body from the cited permitted sibling, with target clock width.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x325a90 BGSMusicSilenceTrack::DoUpdate
// BGSMusicSilenceTrack, DoUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoUpdate: SIBLING(fo4-private@1b765c70, author-permission); adapted timing shape with target clock width
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSilenceTrack.cpp:36
// GetTickCount: OBSERVED; Windows timer import
#include "BGSMusicSilenceTrack_325a90.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

void BGSMusicSilenceTrack::DoUpdate()
{
    std::uint32_t durationMS = static_cast<std::uint32_t>(duration * 1000.0f);
    if (GetMusicStatus() == MUSIC_STATUS::kPlaying) {
        const auto now = GetTickCount();
        if (static_cast<std::uint64_t>(now) - playTime > durationMS) {
            trackStatus = MUSIC_STATUS::kFinished;
        }
    }
}
