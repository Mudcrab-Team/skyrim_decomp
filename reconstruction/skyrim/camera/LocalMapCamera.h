// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// LocalMapCamera::~LocalMapCamera: SIBLING(fo4-private@1b765c70, author-permission); target wrapper uses independently observed behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/LocalMap.cpp:43
// LocalMapCamera, TESCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/L/LocalMapCamera.h and include/RE/T/TESCamera.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
void operator delete(void*, unsigned long long) noexcept;
struct Point2 { float x,y; }; struct Point3 { float x,y,z; };
class TESCamera { public: virtual ~TESCamera(); Point2 rotationInput; Point3 translationInput; float zoomInput; void* cameraRoot; void* currentState; bool enabled; unsigned char pad31; unsigned short pad32; unsigned pad34; };
class LocalMapCamera : public TESCamera { public: virtual ~LocalMapCamera(); Point3 maxExtent, minExtent; void* defaultState; void* camera; float zRotation; unsigned pad64; };
