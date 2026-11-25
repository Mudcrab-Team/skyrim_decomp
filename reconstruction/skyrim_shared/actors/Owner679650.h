// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x69f9e0 (skyrim_shared/actors/Actor_69f9e0): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function679650, Owner679650: GUESS(low) STANDIN
#pragma once
#include "Actor_69f9e0.h"

class Owner679650 : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState, public BSTEventSink<BSTransformDeltaEvent>, public BSTEventSink<bhkCharacterMoveFinishEvent>, public IPostAnimationChannelUpdateFunctor { public: unsigned boolBits; float updateTargetTimer; unsigned criticalStage; AIProcess* currentProcess; void Function679650(); };

