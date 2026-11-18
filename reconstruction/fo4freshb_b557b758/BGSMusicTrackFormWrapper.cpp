// Source exposure: mixed (pinned target listing, community declarations, sibling hints).
// Origin: adapted sibling source and target listing.
// BGSMusicTrackFormWrapper::DoFinish: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:158
// BGSMusicTrackFormWrapper::DoPause: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:148
// BGSMusicTrackFormWrapper::DoPlay: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:138
// BGSMusicTrackFormWrapper::DoUpdate: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:128
// BGSMusicTrackFormWrapper::GetDurationImpl: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:168
// BGSMusicTrackFormWrapper::GetMusicStatus: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:198
// BGSMusicTrackFormWrapper::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:178
// BGSMusicTrackFormWrapper::TestCanPlay: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:188
// BGSMusicTrackFormWrapper::DoClearDucking: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:218
// BGSMusicTrackFormWrapper::DoSetDuckingAttenuation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicTrackFormWrapper.cpp:208
// 0x327660 BGSMusicTrackFormWrapper::DoFinish
// 0x327670 BGSMusicTrackFormWrapper::DoPause
// 0x327680 BGSMusicTrackFormWrapper::DoPlay
// 0x3276a0 BGSMusicTrackFormWrapper::DoUpdate
// 0x3276b0 BGSMusicTrackFormWrapper::GetDurationImpl
// 0x3276c0 BGSMusicTrackFormWrapper::GetMusicStatus
// 0x3276d0 BGSMusicTrackFormWrapper::GetType
// 0x327790 BGSMusicTrackFormWrapper::TestCanPlay
// 0x327650 BGSMusicTrackFormWrapper::DoClearDucking
// 0x327690 BGSMusicTrackFormWrapper::DoSetDuckingAttenuation
#include "BGSMusicTrackFormWrapper.h"
void BGSMusicTrackFormWrapper::DoUpdate() { track->DoUpdate(); }
void BGSMusicTrackFormWrapper::DoPlay() { track->DoPlay(); }
void BGSMusicTrackFormWrapper::DoPause() { track->DoPause(); }
void BGSMusicTrackFormWrapper::DoFinish(bool immediate, float fadeTime) { track->DoFinish(immediate, fadeTime); }
float BGSMusicTrackFormWrapper::GetDurationImpl() const { return track->GetDurationImpl(); }
std::uint32_t BGSMusicTrackFormWrapper::GetType() const { return track->GetType(); }
bool BGSMusicTrackFormWrapper::TestCanPlay() const { return track->TestCanPlay(); }
BSIMusicTrack::MusicStatus BGSMusicTrackFormWrapper::GetMusicStatus() const { return track->GetMusicStatus(); }

void BGSMusicTrackFormWrapper::DoSetDuckingAttenuation(std::uint16_t ducking) { track->DoSetDuckingAttenuation(ducking); }
void BGSMusicTrackFormWrapper::DoClearDucking() { track->DoClearDucking(); }
