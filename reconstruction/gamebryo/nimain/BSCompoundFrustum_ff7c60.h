// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, SetCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAVObject, NiCamera, NiTransform, NiFrustumPlanes, BSCompoundFrustumOperator, BSTArray, BSTArrayHeapAllocator, BSTArrayBase, Set, rotate, translate, scale, world, worldToCam, viewFrustum, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, planes, functionOperators, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "generated/crashlogger_pdb/types/NiFrustum.h"
#include "generated/crashlogger_pdb/types/NiMatrix3.h"
#include "generated/crashlogger_pdb/types/NiPlane.h"
#include "generated/crashlogger_pdb/types/NiPoint3.h"

struct BSCompoundFrustumOperator;

struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};

class NiAVObject
{
public:
    unsigned char unrecovered00[0x7c];
    NiTransform world;
    unsigned char unrecoveredB0[0x60];
};

class NiCamera : public NiAVObject
{
public:
    float worldToCam[4][4];
    NiFrustum viewFrustum;
};

class NiFrustumPlanes
{
public:
    void Set(const NiFrustum& frustum, const NiTransform& transform);
private:
    NiPlane cullingPlanes[6];
    unsigned int activePlanes;
    unsigned int basePlaneStates;
    unsigned int unk68;
    unsigned int unk6C;
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
};

class BSCompoundFrustum
{
public:
    void SetCamera(NiCamera* newCamera);
private:
    BSTArray<NiFrustumPlanes> planes;
    BSTArray<BSCompoundFrustumOperator> functionOperators;
    NiFrustumPlanes viewFrustum;
    NiPoint3 viewPosition;
    NiCamera* camera;
    unsigned int freePlane;
    unsigned int freeOp;
    unsigned int firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};
