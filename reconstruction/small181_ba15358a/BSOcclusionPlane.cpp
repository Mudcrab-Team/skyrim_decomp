// Origin: original reconstruction; declarations adapted from powerof3/CommonLibSSE, GPL-3.0, include/RE/B/BSOcclusionPlane.h, BSOcclusionShape.h, BSCompoundFrustum.h, BSTArray.h and include/RE/N/NiFrustumPlanes.h, NiPlane.h, NiMatrix3.h, NiPoint2.h, NiPoint3.h, NiRefObject.h, NiObject.h.
// Source exposure: mixed (binary-analysis and community headers).
// BSOcclusionPlane, BSOcclusionShape, NiObject, NiRefObject, NiPoint2, NiPoint3, NiMatrix3, NiPlane, NiFrustumPlanes, BSCompoundFrustum, BSTArray, translation, rotation, updateFacesOrVertices, size, frustum, planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Refresh, GetFrustum: GUESS(low)
// 0xfe8e40 BSOcclusionPlane::GetFrustum
#include "BSOcclusionPlane.h"
BSCompoundFrustum* BSOcclusionPlane::GetFrustum() { Refresh(); return &frustum; }
