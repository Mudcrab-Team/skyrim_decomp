// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ShiftOperators, NiFrustumPlanes, NiPlane, NiPoint3, BSCompoundFrustumOperator, BSCompoundFrustumOperatorType, BSTArray, BSTArrayHeapAllocator, BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, type, onPass, onFail: CRASHLOGGER_PDB(59818@2026.10.24)
// Resize: GUESS(low)
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
    BSCompoundFrustumOperatorType type;
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

class BSCompoundFrustum
{
public:
    void ShiftOperators(int shift, bool clearVacated);

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
