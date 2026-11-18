// Origin: original reconstruction; declarations adapted from powerof3/CommonLibSSE, GPL-3.0, include/RE/B/BSOcclusionPlane.h, BSOcclusionShape.h, BSCompoundFrustum.h, BSTArray.h and include/RE/N/NiFrustumPlanes.h, NiPlane.h, NiMatrix3.h, NiPoint2.h, NiPoint3.h, NiRefObject.h, NiObject.h.
// Source exposure: mixed (binary-analysis and community headers).
// BSOcclusionPlane, BSOcclusionShape, NiObject, NiRefObject, NiPoint2, NiPoint3, NiMatrix3, NiPlane, NiFrustumPlanes, BSCompoundFrustum, BSTArray, translation, rotation, updateFacesOrVertices, size, frustum, planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Refresh, GetFrustum: GUESS(low)
#pragma once
#include <cstdint>
struct NiPoint2 { float x, y; };
struct NiPoint3 { float x, y, z; };
struct NiMatrix3 { float entry[3][3]; };
struct NiPlane { NiPoint3 normal; float constant; };
struct NiFrustumPlanes { NiPlane cullingPlanes[6]; std::uint32_t activePlanes, basePlaneStates, unk68, unk6C; };
struct BSTArrayHeapAllocator { void* data; std::uint32_t capacity; };
struct BSTArrayBase { std::uint32_t size; };
template<class T> struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase {};
class NiCamera;
struct BSCompoundFrustum { BSTArray<NiFrustumPlanes> planes; BSTArray<void*> functionOperators; NiFrustumPlanes viewFrustum; NiPoint3 viewPosition; NiCamera* camera; std::uint32_t freePlane, freeOp, firstOp; bool skipViewFrustum, prethreaded; };
class NiRefObject { public: virtual ~NiRefObject(); volatile std::uint32_t refCount; std::uint32_t pad0C; };
class NiObject : public NiRefObject {};
class BSOcclusionShape : public NiObject { public: NiPoint3 translation; NiMatrix3 rotation; float unk40; bool updateFacesOrVertices; };
class BSOcclusionPlane : public BSOcclusionShape { public: BSCompoundFrustum* GetFrustum(); void Refresh(); NiPoint2 size; BSCompoundFrustum frustum; };
