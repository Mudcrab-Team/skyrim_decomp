// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSMusicSingleTrack::GetDurationImpl: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSingleTrack.cpp:182
// BGSMusicSingleTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSMusicSingleTrack.h, include/RE/B/BGSMusicTrack.h, include/RE/B/BSIMusicTrack.h, include/RE/B/BSSoundHandle.h and include/RE/I/ID.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3269d0 BGSMusicSingleTrack::GetDurationImpl
#include "BGSMusicSingleTrack_3269d0.h"
float BGSMusicSingleTrack::GetDurationImpl() const { return float(trackHandle.GetDuration()) * 0.001f; }
