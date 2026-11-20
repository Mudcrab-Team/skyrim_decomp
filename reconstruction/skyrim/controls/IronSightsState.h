// Source exposure: mixed
// Code origin: IronSightsState::GetRotation was adapted from the anonymous fo4-private sibling as labelled (author permission); IronSightsState::GetCurrentPosition was written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// IronSightsState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/IronSightsState.cpp:37
// TESCameraState, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESCameraState.h, include/RE/N/NiAVObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiRefObject.h and include/RE/N/NiTransform.h.
// names: GUESS(low); names and original signatures are tentative.
// IronSightsState::GetCurrentPosition: GUESS(low); the pinned community header declares no such name for this slot
// identityPosition: GUESS(low); the fallback position constant has no public name
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct NiMatrix3 { float entries[3][3]; }; struct NiPoint3 { float x,y,z; }; struct NiTransform { NiMatrix3 rotation; NiPoint3 translation; float scale; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject { public: const char* name; void* controllers; void** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public: void* parent; unsigned parentIndex, unknown; void* collision; NiTransform local, world; };
class NiQuaternion { public: float w,x,y,z; void FromRotation(const NiMatrix3&); };
extern const NiQuaternion identityQuaternion;
extern const NiPoint3 identityPosition;
class TESCameraState { public: virtual ~TESCameraState(); unsigned refCount, pad; void* camera; unsigned id, pad2; };
class IronSightsState : public TESCameraState { public: NiAVObject* cameraObject; void GetRotation(NiQuaternion&) const; void GetCurrentPosition(NiPoint3& a_out) const; };
