// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSMusicSingleTrack::GetDurationImpl, BGSMusicSingleTrack::DoClearDucking, BGSMusicSingleTrack::DoSetDuckingAttenuation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSingleTrack.cpp:182
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSingleTrack.cpp:176
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSingleTrack.cpp:170
// BGSMusicSingleTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSMusicSingleTrack.h, include/RE/B/BGSMusicTrack.h, include/RE/B/BSIMusicTrack.h, include/RE/B/BSSoundHandle.h and include/RE/I/ID.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct ResourceID { unsigned file, extension, directory; };
struct FloatArray { float* data; unsigned capacity; unsigned allocatorPad; unsigned size; unsigned sizePad; };
class SoundHandle { public: unsigned id; bool success; unsigned char pad; unsigned short pad2; unsigned state; unsigned GetDuration() const; void FadeTo(unsigned short, unsigned short); };
class MusicTrackInterface { public: virtual ~MusicTrackInterface(); unsigned status; };
class BGSMusicTrack : public MusicTrackInterface { public: void* conditions; unsigned long long unknown; };
extern float musicUnduckingSeconds, musicDuckingSeconds;
unsigned short ClampFadeTimeSeconds(float);
class BGSMusicSingleTrack : public BGSMusicTrack { public: ResourceID trackID, finaleID; FloatArray cuePoints; unsigned nextCue, loopsRemaining, lastPosition, pad; void* loopData; SoundHandle trackHandle; float GetDurationImpl() const; void DoClearDucking(); void DoSetDuckingAttenuation(unsigned short); };
