// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// LocalMapCamera::DefaultState::Begin: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/LocalMap.cpp:190
// LocalMapCamera::DefaultState, TESCameraState, NiPoint3: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/L/LocalMapCamera.h, include/RE/T/TESCameraState.h and include/RE/N/NiPoint3.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct NiPoint3 { float x,y,z; static const NiPoint3 ZERO; };
class TESCameraState { public: virtual ~TESCameraState(); unsigned int refCount; void* camera; unsigned int id; };
class LocalMapCamera { public: class DefaultState : public TESCameraState { public: void Begin(); NiPoint3 initialPosition; NiPoint3 translation; float zoom; }; };
