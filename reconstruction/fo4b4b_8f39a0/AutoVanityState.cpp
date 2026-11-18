// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// AutoVanityState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/AutoVanityState.cpp:69
// TESCameraState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8f39a0 AutoVanityState::GetRotation
#include "AutoVanityState.h"
void AutoVanityState::GetRotation(NiQuaternion& value) const { value.FromEulerAnglesXYZ(0.0f, 0.0f, rotation); }
