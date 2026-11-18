// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x644870 BGSMoviePlayer::Unk_03
// 0x6448a0 BGSMoviePlayer::Unk_04
#include "BGSMoviePlayer.h"
void BGSMoviePlayer::Unk_03() { BSMusicEvent event; event.musicType = nullptr; event.msgType = BSMusicEvent::MUSIC_MESSAGE_TYPE::kPause; SendEvent(&event); }
void BGSMoviePlayer::Unk_04() { BSMusicEvent event; event.musicType = nullptr; event.msgType = BSMusicEvent::MUSIC_MESSAGE_TYPE::kUnpause; SendEvent(&event); }
