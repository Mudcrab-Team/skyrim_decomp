// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// p202_ad7bf36d: GUESS(low)
// Origin: adapted declarations from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, include/RE/B/BGSMusicSingleTrack.h and BSIMusicTrack.h; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// p202_ad7bf36d: GUESS(low)
// BGSMusicSingleTrack, GetType, TrackType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// registeredType, typeName, RegisterType: GUESS(low)
// BGSMusicSingleTrack: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
namespace p202_ad7bf36d {
extern std::uint32_t registeredType;
extern const char typeName[];
void RegisterType(std::uint32_t*, const char*, void*);
}
enum class TrackType : std::uint32_t {};
class BGSMusicSingleTrack {
public:
 TrackType GetType() const;
};
