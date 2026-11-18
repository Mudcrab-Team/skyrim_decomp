// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/B/BSIMusicType.h, BSIMusicTrack.h and BSTArray.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); BGSMusicType represents its music interface subobject here.
#pragma once
class BSIMusicTrack { public: virtual ~BSIMusicTrack(); virtual void DoUpdate(); virtual void DoPlay(); virtual void DoPause(); virtual void DoFinish(bool,float); virtual float GetDurationImpl() const; virtual unsigned GetType() const; virtual bool TestCanPlay() const; virtual unsigned GetMusicStatus() const; virtual void DoSetDuckingAttenuation(unsigned short); virtual void DoClearDucking(); };
template<class T> struct ArrayAllocator { T* data; unsigned capacity; }; struct ArrayBase { unsigned size; }; template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
class BGSMusicType { public: virtual void DoUpdate(); virtual void DoPlay(); virtual void DoPause(); virtual void DoFinish(bool); virtual void DoApplyDuckingAttenuation(unsigned short); virtual void DoClearDucking(); virtual void DoPrepare(); virtual ~BGSMusicType(); unsigned flags; unsigned char priority, padding; unsigned short ducksOtherMusicBy; float fadeTime; unsigned currentTrackIndex; Array<unsigned> trackHistory; Array<BSIMusicTrack*> tracks; };
