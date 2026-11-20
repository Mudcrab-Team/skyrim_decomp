// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/F/FreeCameraState.h, include/RE/T/TESCameraState.h, include/RE/P/PlayerInputHandler.h, include/RE/B/BSIntrusiveRefCounted.h, include/RE/N/NiMatrix3.h and include/RE/N/NiQuaternion.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiPoint2 { float x,y; }; class NiMatrix3 { public: float entry[3][3]; void FromEulerAnglesZXY(float,float,float); }; class NiQuaternion { public: void FromRotation(const NiMatrix3&); }; class TESCamera;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; }; class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; }; class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class FreeCameraState : public TESCameraState, public PlayerInputHandler { public: NiPoint3 translation; NiPoint2 rotation, zUpDown; short verticalDirection; bool useRunSpeed, lockToZPlane; void GetRotation(NiQuaternion&) const; };
