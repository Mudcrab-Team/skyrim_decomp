// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// LocalMapCamera::DefaultState::Begin: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/LocalMap.cpp:190
// LocalMapCamera::DefaultState, TESCameraState, NiPoint3: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/L/LocalMapCamera.h, include/RE/T/TESCameraState.h and include/RE/N/NiPoint3.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2492a0 LocalMapCamera::DefaultState::Begin
#include "LocalMapCamera.h"
void LocalMapCamera::DefaultState::Begin() { translation.x = NiPoint3::ZERO.x; translation.y = NiPoint3::ZERO.y; translation.z = NiPoint3::ZERO.z; zoom = 0.5f; }
