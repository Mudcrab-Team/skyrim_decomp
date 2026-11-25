// Source exposure: mixed
// Code origin: The stand-in follows the matched HorseCameraState exemplar and its pinned community declarations. Padding places horseRefHandle at the offset used by this twin.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function10db0b0, Owner10db0b0: GUESS(low) STANDIN
// ThirdPersonState: GUESS(low) STANDIN
#pragma once
#include "HorseCameraState.h"

class Owner10db0b0 : public ThirdPersonState { public: ~Owner10db0b0(); unsigned char padTwinE8[48]; unsigned horseRefHandle; float horseCurrentDirection; bool atMaxHorseAngle; void Function10db0b0(unsigned& a_handle); void End(); void Revert(BGSLoadFormBuffer*); };
static_assert(sizeof(Owner10db0b0) == 0x128, "Owner10db0b0 size");
