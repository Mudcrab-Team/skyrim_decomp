// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, NiFrustumPlanes, NiPlane, NiPoint3, BSCompoundFrustumOperator, BSCompoundFrustumOperatorType, BSTArray, BSTArrayHeapAllocator, BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// planes, functionOperators, viewFrustum, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, type, onPass, onFail: CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AllocStorage, ReallocStorage, ConstructRange, ResizeConstructed, ResizeTrivial, ZERO: GUESS(low)
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

namespace NiPoint3Constants
{
    extern const NiPoint3 ZERO;
}

struct NiPlane
{
    NiPlane();

    NiPoint3 normal;
    float constant;
};

struct NiFrustumPlanes
{
    NiFrustumPlanes() : activePlanes(0x3Fu), basePlaneStates(0x3Fu) {}

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
    BSTArrayHeapAllocator();
    ~BSTArrayHeapAllocator();

    bool AllocStorage(unsigned int count, unsigned int elemSize);
    bool ReallocStorage(unsigned int newCap, unsigned int oldSize, unsigned int unused1, unsigned int unused2, unsigned int elemSize);

    void* data;
    unsigned int capacity;
};

struct BSTArrayBase
{
    BSTArrayBase();

    unsigned int size;
};

template <typename T>
struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase
{
    ~BSTArray();
    void ConstructRange(unsigned int start, unsigned int count);

    void ResizeConstructed(unsigned int newSize)
    {
        unsigned int oldSize = size;
        if (oldSize != newSize) {
            if (capacity < newSize) {
                bool ok = (capacity == 0)
                    ? AllocStorage(newSize, sizeof(T))
                    : ReallocStorage(newSize, oldSize, 0, 0, sizeof(T));
                if (!ok) {
                    return;
                }
                ConstructRange(size, newSize - size);
            } else if (oldSize <= newSize) {
                ConstructRange(oldSize, newSize - oldSize);
            }
        }
        size = newSize;
    }

    void ResizeTrivial(unsigned int newSize)
    {
        unsigned int oldSize = size;
        if (oldSize != newSize) {
            if (capacity < newSize) {
                bool ok = (capacity == 0)
                    ? AllocStorage(newSize, sizeof(T))
                    : ReallocStorage(newSize, oldSize, 0, 0, sizeof(T));
                if (!ok) {
                    return;
                }
            }
        }
        size = newSize;
    }
};

class BSCompoundFrustum
{
public:
    BSCompoundFrustum();

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
static_assert(sizeof(BSCompoundFrustum) == 0xc8, "BSCompoundFrustum size");
