// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// p202_ad7bf36d: GUESS(low)
// Origin: adapted declarations from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, include/RE/B/BGSMusicSingleTrack.h and BSIMusicTrack.h; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// 0x326c50 BGSMusicSingleTrack::GetType
#include "BGSMusicSingleTrack.h"
using namespace p202_ad7bf36d;
TrackType BGSMusicSingleTrack::GetType() const
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return static_cast<TrackType>(registeredType);
}
