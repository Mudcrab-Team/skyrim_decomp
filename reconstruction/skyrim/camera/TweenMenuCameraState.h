// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// TweenMenuCameraState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/TweenMenuCameraState.cpp:37
// TweenMenuCameraState: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declaration adapted from include/RE/T/TweenMenuCameraState.h.
// The declaration derived from powerof3/CommonLibSSE is GPL-3.0.
// PlayerCamera, TESCameraState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESCameraState.h and include/RE/B/BSTArray.h and include/RE/B/BSAtomic.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct Point2 { float x,y; }; struct Point3 { float x,y,z; }; struct Quaternion { float w,x,y,z; };
class TESCameraState;
class TESCamera { public: virtual ~TESCamera(); Point2 rotationInput; Point3 translationInput; float zoomInput; void* cameraRoot; TESCameraState* currentState; bool enabled; unsigned char pad31; unsigned short pad32; unsigned pad34; };
class Singleton {};
struct SmallStates { unsigned capacity:31, local:1; union { TESCameraState** heap; TESCameraState* localData[13]; }; unsigned size; };
class PlayerCamera : public TESCamera, public Singleton { public: unsigned char pad39; unsigned short pad3a; unsigned cameraTarget; SmallStates tempReturnStates; TESCameraState* cameraStates[13]; void* unknown120; void* rigidBody; unsigned objectFadeHandle; struct SpinLock { unsigned owningThread, lockCount; } lock; float worldFOV; };
class TESCameraState { public: virtual ~TESCameraState(); unsigned refCount, pad; TESCamera* camera; unsigned id, pad2; };
class TweenMenuCameraState : public TESCameraState { public: Quaternion initialRotation; float initialFOV; Point2 currentAddedRot, targetAddedRot; float currentAddedFOV, targetAddedFOV; bool endingState; void End(); };
