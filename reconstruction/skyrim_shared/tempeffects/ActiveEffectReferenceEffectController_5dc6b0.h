// Adapted declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); paths listed below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations and field names: GUESS; selected offsets and call slots corroborated by target.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
#include <cstdint>
class Actor; class MagicTarget; class TESObjectREFR; class NiNode; class BSFixedString; class BGSSaveFormBuffer; class BGSLoadFormBuffer;
struct NiPoint3 { float x,y,z; };
class ActiveEffect { public: virtual void AdjustForPerks(Actor*,MagicTarget*); virtual void OnAdd(MagicTarget*); virtual void OnRemove(); virtual TESObjectREFR* GetVisualsTarget(); virtual void Update(float); virtual void EvaluateConditions(float,bool); virtual bool IsCausingHealthDamage(); virtual void SetLocation(const NiPoint3&); virtual void SaveGame(BGSSaveFormBuffer*); virtual void LoadGame(BGSLoadFormBuffer*); virtual void FinishLoadGame(BGSLoadFormBuffer*); virtual void Revert(BGSLoadFormBuffer*); virtual std::int32_t Compare(ActiveEffect*); virtual void HandleEvent(const BSFixedString&); virtual void SwitchAttachedRoot(NiNode*,NiNode*); };
class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: void HandleEvent(const BSFixedString&); void SwitchAttachedRoot(NiNode*,NiNode*); void SetWindPoint(const NiPoint3&); ActiveEffect* effect; std::uint32_t target; NiPoint3 windPoint; };
