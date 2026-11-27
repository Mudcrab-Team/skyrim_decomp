// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ProcessPortal, BSPortal, BSOcclusionPlane, NiFrustumPlanes, NiPlane, NiPoint3, BSCompoundFrustumOperator, BSCompoundFrustumOperatorType, BSTArray, BSTArrayHeapAllocator, BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, type, onPass, onFail, InsidePlanes, IntersectsPlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// planeIndex, ZERO: GUESS(low)
#pragma once

#include "generated/crashlogger_pdb/types/BSCompoundFrustumOperatorType.h"
#include "generated/crashlogger_pdb/types/NiPlane.h"
#include "generated/crashlogger_pdb/types/NiPoint3.h"

class NiCamera;

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
    T& operator[](unsigned int index)
    {
        return static_cast<T*>(data)[index];
    }
};

struct BSOcclusionPlane
{
    bool IntersectsPlanes(const NiFrustumPlanes& planes, bool flag, const NiPoint3& origin);
    bool InsidePlanes(const NiFrustumPlanes& planes);
};

struct BSPortal : BSOcclusionPlane
{
};

namespace NiPoint3Constants
{
    extern const NiPoint3 ZERO;
}

class BSCompoundFrustum
{
public:
    bool ProcessPortal(BSPortal* portal);

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
