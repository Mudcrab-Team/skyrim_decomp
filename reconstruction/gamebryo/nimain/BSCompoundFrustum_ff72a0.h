// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSCompoundFrustum, planes, functionOperators, NiFrustumPlanes, BSCompoundFrustumOperator, BSTArrayHeapAllocator and BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryArray and Clear: GUESS(low)
#pragma once

#include "GeometryArray.h"
#include "PortalHeapObject.h"

struct NiFrustumPlanes;
struct BSCompoundFrustumOperator;
struct BSPortal;
class BSOcclusionShape;
class BSOcclusionBox;
class BSMultiBoundShape;

struct BSCompoundFrustum : PortalHeapObject {
    BSCompoundFrustum();
    ~BSCompoundFrustum();
    static BSCompoundFrustum* AllocateFromPool();
    static void ReleaseToPool(BSCompoundFrustum* frustum);
    void Prethread();
    void AddOcclusionShapeIfVisible(BSOcclusionShape* shape, BSCompoundFrustum* test);
    bool ProcessPortal(BSPortal* portal);
    bool ProcessMultiBoundShape(BSMultiBoundShape* shape);
    void AddPortal(BSPortal* portal);
    bool AddOcclusionBox(BSOcclusionBox* box);

    GeometryArray<NiFrustumPlanes> planes;
    GeometryArray<BSCompoundFrustumOperator> functionOperators;
    unsigned char unknown30[0x98];
};
static_assert(sizeof(BSCompoundFrustum) == 0xc8, "frustum pool slot stride");
