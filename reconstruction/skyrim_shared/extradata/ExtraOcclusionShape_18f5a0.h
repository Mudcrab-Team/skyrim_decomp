// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: reconstruction from the pinned image listing; see Adapted bodies.
// Adapted bodies: OcclusionShapePtr::~OcclusionShapePtr, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// ExtraOcclusionShape, BSExtraData, BSOcclusionShape, shape: CRASHLOGGER_PDB(59818@2026.10.24)
// OcclusionShapePtr, DeleteThis, refCount, next: GUESS(low)
#pragma once

#include <intrin.h>
#include <cstdint>

class BSOcclusionShape
{
public:
    virtual ~BSOcclusionShape();
    virtual void DeleteThis();  // slot 01 (+0x08)

    long refCount;
    std::uint32_t reserved0C;
};

struct OcclusionShapePtr
{
    ~OcclusionShapePtr()
    {
        BSOcclusionShape* obj = ptr;
        if (obj) {
            // atomic reference decrement before virtual deletion
            if (_InterlockedExchangeAdd(&obj->refCount, -1) == 1) {
                obj->DeleteThis();
            }
        }
    }

    BSOcclusionShape* ptr;
};

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;  // 08
};

class ExtraOcclusionShape : public BSExtraData
{
public:
    ExtraOcclusionShape();  // implicit deleting dtor compared: 0x18f5a0

    OcclusionShapePtr shape;  // 10
};
static_assert(sizeof(ExtraOcclusionShape) == 0x18, "size");
