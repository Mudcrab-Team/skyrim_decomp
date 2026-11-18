// CreateRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); output parameter declaration adapted from include/RE/M/Misc.h; target callee identity remains inferred.
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// PlayerCamera::SetCameraTarget: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCamera.cpp:272
// PlayerCamera, TESCamera, BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESObjectREFR.h, include/RE/B/BSHandleRefObject.h and include/RE/B/BSPointerHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class BSHandleRefObject : public NiRefObject {};
class TESObjectREFR : public TESForm, public BSHandleRefObject {};
class Actor : public TESObjectREFR {};

extern unsigned nullHandle;
void CreateRefHandle(unsigned&, TESObjectREFR*);
struct Point2 { float x,y; }; struct Point3 { float x,y,z; };
class TESCamera { public: virtual ~TESCamera(); Point2 rotationInput; Point3 translationInput; float zoomInput; void* cameraRoot; void* currentState; bool enabled; unsigned char pad31; unsigned short pad32; unsigned pad34; };
class Singleton {};
class PlayerCamera : public TESCamera, public Singleton { public: unsigned char pad39; unsigned short pad3a; unsigned cameraTarget; void SetCameraTarget(Actor*); };
