// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, AddPortalOpening, BSPortal, BSOcclusionPlane, GetCorners, CopyFrustumPlanes, NiFrustumPlanes, NiPlane, NiPoint3, BSCompoundFrustumOperator, BSCompoundFrustumOperatorType, BSTArray, BSTArrayHeapAllocator, BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, type, onPass, onFail: CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// planeIndex, Resize, SignedDistance: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include "generated/crashlogger_pdb/types/BSCompoundFrustumOperatorType.h"

class NiCamera;

struct NiPoint3
{
    NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}

    float x;
    float y;
    float z;
};

struct NiPlane
{
    NiPlane(const NiPoint3& p0, const NiPoint3& p1, const NiPoint3& p2);

    float SignedDistance(const NiPoint3& point) const
    {
        return normal.x * point.x + normal.y * point.y + normal.z * point.z - constant;
    }

    NiPoint3 normal;
    float constant;
};

struct NiFrustumPlanes
{
    NiPlane cullingPlanes[6];
    unsigned int activePlanes;
    unsigned int basePlaneStates;
    unsigned int unk68;
    unsigned int unk6C;
};

struct BSCompoundFrustumOperator
{
    union
    {
        BSCompoundFrustumOperatorType type;
        unsigned int planeIndex;
    };
    unsigned int onPass;
    unsigned int onFail;
};

struct BSTArrayHeapAllocator
{
    void* data;
    unsigned int capacity;
};

struct BSTArrayBase
{
    unsigned int size;
};

template <typename T>
struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase
{
    void Resize(int newSize);

    T& operator[](unsigned int index)
    {
        return static_cast<T*>(data)[index];
    }
};

struct BSOcclusionPlane
{
    void GetCorners(NiPoint3* corners);
    void CopyFrustumPlanes(const NiPoint3& position, NiFrustumPlanes& result);
};

struct BSPortal : BSOcclusionPlane
{
};

class BSCompoundFrustum
{
public:
    void AddPortalOpening(BSPortal* portal);

private:
    BSTArray<NiFrustumPlanes> planes;
    BSTArray<BSCompoundFrustumOperator> functionOperators;
    NiFrustumPlanes viewFrustum;
    NiPoint3 viewPosition;
    NiCamera* camera;
    int freePlane;
    int freeOp;
    unsigned int firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};
