// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PlayerCamera: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8fa270 PlayerCamera::Function8fa270
// 0x8f94c0 PlayerCamera::Function8f94c0
#include "PlayerCamera_8f94c0.h"
void PlayerCamera::Function8fa270() {
 if (unk165) {
  SetState(GetTargetState());
  unk165 = 0;
 }
}
void PlayerCamera::Function8f94c0() {
 if (currentState.ptr == cameraStates[4].ptr) SetState(GetTargetState());
}
