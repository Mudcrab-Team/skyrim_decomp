// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PlayerCamera: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// PlayerCamera, TESCamera, BSTSmallArray, BSTArrayBase, BSTSmallArrayHeapAllocator, BSTSingletonSDM, BSTSmartPointer, NiPointer, BSSpinLock, BSTPoint2, BSTPoint3, NiPoint3, ObjectRefHandle, ActorHandle, Unk120, TESCameraState, cameraStates, currentState, tempReturnStates, unk165, SetState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function8fa270, Function8f94c0, GetTargetState, ptr: GUESS(low)
class NiNode; class TESCameraState; class bhkRigidBody;
template<class T> class NiPointer { public: T* ptr; };
template<class T> class BSTSmartPointer { public: T* ptr; };
struct BSTArrayBase { std::uint32_t size; };
template<class T, std::uint32_t N> struct BSTSmallArrayHeapAllocator {
 std::uint32_t capacity:31; std::uint32_t local:1;
 union Data { void* heap; T localValues[N]; } data;
};
template<class T, std::uint32_t N> struct BSTSmallArray : BSTSmallArrayHeapAllocator<T,N>, BSTArrayBase {};
template<class T> struct BSTSingletonSDMOpStaticBuffer {};
template<class T, class Alloc = BSTSingletonSDMOpStaticBuffer<T>> struct BSTSDMTraits { using Type=T; using Allocator=Alloc; };
template<class Traits> struct BSTSingletonSDMBase : Traits, Traits::Allocator {};
template<class T> struct BSTSingletonSDM : BSTSingletonSDMBase<BSTSDMTraits<T>> {};
template<class T> struct BSTPoint2 { T x,y; };
template<class T> struct BSTPoint3 { T x,y,z; };
struct NiPoint3 { float x,y,z; };
struct BSSpinLock { volatile std::uint32_t owningThread, lockCount; };
struct ObjectRefHandle { std::uint32_t value; };
struct ActorHandle { std::uint32_t value; };
class TESCamera {
public:
 virtual ~TESCamera();
 void SetState(TESCameraState*);
 BSTPoint2<float> rotationInput;
 BSTPoint3<float> translationInput;
 float zoomInput;
 NiPointer<NiNode> cameraRoot;
 BSTSmartPointer<TESCameraState> currentState;
 bool enabled;
 std::uint8_t pad31;
 std::uint16_t pad32;
 std::uint32_t pad34;
};
class PlayerCamera : public TESCamera, public BSTSingletonSDM<PlayerCamera> {
public:
 TESCameraState* GetTargetState();
 void Function8fa270();
 void Function8f94c0();
 std::uint8_t pad039;
 std::uint16_t pad03A;
 ActorHandle cameraTarget;
 BSTSmallArray<TESCameraState*, 13> tempReturnStates;
 BSTSmartPointer<TESCameraState> cameraStates[13];
 struct Unk120;
 Unk120* unk120;
 NiPointer<bhkRigidBody> rigidBody;
 ObjectRefHandle objectFadeHandle;
 BSSpinLock lock;
 float worldFOV, firstPersonFOV;
 NiPoint3 pos;
 float idleTimer, yaw;
 std::uint32_t unk158, unk15C;
 bool allowAutoVanityMode, bowZoomedIn, isWeapSheathed, isProcessed;
 std::uint8_t unk164, unk165;
};
