// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// IronSightsState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/IronSightsState.cpp:37
// TESCameraState, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h and include/RE/N/NiTransform.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct NiMatrix3 { float entries[3][3]; }; struct NiPoint3 { float x,y,z; }; struct NiTransform { NiMatrix3 rotation; NiPoint3 translation; float scale; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject { public: const char* name; void* controllers; void** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public: void* parent; unsigned parentIndex, unknown; void* collision; NiTransform local, world; };
class NiQuaternion { public: float w,x,y,z; void FromRotation(const NiMatrix3&); };
extern const NiQuaternion identityQuaternion;
class TESCameraState { public: virtual ~TESCameraState(); unsigned refCount, pad; void* camera; unsigned id, pad2; };
class IronSightsState : public TESCameraState { public: NiAVObject* cameraObject; void GetRotation(NiQuaternion&) const; };
