// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x5c2cb0 (skyrim/magic/ActorMagicCaster_5c2cb0): source copied, names replaced by placeholders.
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:463
// MagicCaster, SimpleAnimationGraphManagerHolder, RefAttachTechniqueInput: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/A/ActorMagicCaster.h, include/RE/M/MagicCaster.h, include/RE/S/SimpleAnimationGraphManagerHolder.h and include/RE/R/RefAttachTechniqueInput.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function1308a40, Owner1308a40: GUESS(low) STANDIN
#pragma once
#include "ActorMagicCaster_5c2cb0.h"

class Owner1308a40 : public MagicCaster, public SimpleAnimationGraphManagerHolder, public AnimationEventSink { public: Actor* Function1308a40() const; RefAttachTechniqueInput castingArtData; void* cloneTask; Actor* actor; };

