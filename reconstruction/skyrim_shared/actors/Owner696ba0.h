// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x6ca480 (skyrim_shared/actors/Actor_6ca480): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function696ba0, Owner696ba0: GUESS(low) STANDIN
#pragma once
#include "Actor_6ca480.h"

class Owner696ba0 : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState, public BSTEventSink<BSTransformDeltaEvent>, public BSTEventSink<bhkCharacterMoveFinishEvent>, public IPostAnimationChannelUpdateFunctor { public: unsigned boolBits; float updateTargetTimer; unsigned criticalStage; AIProcess* currentProcess; bool Function696ba0() const; };

