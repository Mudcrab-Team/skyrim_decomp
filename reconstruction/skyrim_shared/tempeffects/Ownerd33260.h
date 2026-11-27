// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed.
// Code origin: declarations adapted from the community headers and extended by hand from the local listings. Stamped as a twin of matched 0x5dcb70 (skyrim_shared/tempeffects/ActiveEffectReferenceEffectController_5dc9d0): source copied, names replaced by placeholders.
// Ownerd33260: GUESS(low) STANDIN
#pragma once
#include "ActiveEffectReferenceEffectController_5dc9d0.h"

class Ownerd33260 : public ReferenceEffectController { public: virtual bool GetManagerHandlesSaveLoad() const; virtual NiPoint3* GetWindPoint(); virtual void LoadGame(BGSLoadFormBuffer* a_buf); void HandleEvent(const BSFixedString&); void SwitchAttachedRoot(NiNode*,NiNode*); void SetWindPoint(const NiPoint3&); ActiveEffect* effect; unsigned char padTwin10[8]; std::uint32_t target; NiPoint3 windPoint; };
